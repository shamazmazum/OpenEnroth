#include <vector>
#include <algorithm>

#include "Engine/Engine.h"
#include "Engine/mm7_data.h"
#include "Engine/Graphics/Indoor.h"
#include "Engine/Graphics/Outdoor.h"
#include "Engine/Graphics/Level/Decoration.h"
#include "Engine/Events/EventMap.h"
#include "Engine/Events/EventIR.h"
#include "Engine/Events/EventInterpreter.h"
#include "Engine/Events/Processor.h"
#include "Engine/Events.h"

struct MapTimer {
    GameTime interval = GameTime(0);
    GameTime altInterval = GameTime(0);
    GameTime alarmTime = GameTime(0);
    int eventId = 0;
    int eventStep = 0;
};

static std::vector<EventTrigger> onMapLoadTriggers;
static std::vector<EventTrigger> onMapLeaveTriggers;

static std::vector<MapTimer> onLongTimerTriggers;
static std::vector<MapTimer> onTimerTriggers;

static void registerTimerTriggers(EventType triggerType, std::vector<MapTimer> *triggers) {
    std::vector<EventTrigger> timerTriggers = engine->_localEventMap.enumerateTriggers(triggerType);
    GameTime levelLastVisit{};

    // TODO(Nik-RE-dev): using time of last visit will help timers only slightly when transiting indoor<->outdoor
    //                   "once" because each saving reset these times.
    //                   To support fair timers they needed to be saved in save game and for each map separately.
    if (uCurrentlyLoadedLevelType == LEVEL_Indoor) {
        levelLastVisit = pIndoor->stru1.last_visit;
    } else {
        levelLastVisit = pOutdoor->loc_time.last_visit;
    }

    triggers->clear();
    for (EventTrigger &trigger : timerTriggers) {
        MapTimer timer;
        EventIR ir = engine->_localEventMap.get(trigger.eventId, trigger.eventStep);

        if (ir.data.timer_descr.alternative_interval) {
            // Alternative interval is defined in terms of half-minutes
            timer.altInterval = GameTime::FromSeconds(ir.data.timer_descr.alternative_interval * 30);
            timer.alarmTime = pParty->GetPlayingTime() + timer.altInterval;
            assert(timer.altInterval.Valid());
        } else {
            timer.interval = GameTime(ir.data.timer_descr.seconds, ir.data.timer_descr.minutes, ir.data.timer_descr.hours,
                                      ir.data.timer_descr.weeks, ir.data.timer_descr.months, ir.data.timer_descr.years);

            if (levelLastVisit) {
                timer.alarmTime = std::max(levelLastVisit + timer.interval, pParty->GetPlayingTime());
            } else {
                timer.alarmTime = pParty->GetPlayingTime() + timer.interval;
            }
            assert(timer.interval.Valid());
        }
        timer.eventId = trigger.eventId;
        timer.eventStep = trigger.eventStep;

        triggers->push_back(timer);
    }
}

void eventProcessor(int eventId, int targetObj, bool canShowMessages, int startStep) {
    if (!eventId) {
        return;
    }

    EvtTargetObj = targetObj; // TODO: pass as local
    dword_5B65C4_cancelEventProcessing = 0; // TODO: rename and contain in this module or better remove it altogether

    // TODO(Nik-RE-dev): linked to old processor for now
    EventProcessor(eventId, targetObj, canShowMessages, startStep);
    return;

    EventInterpreter interpreter;
    bool mapExitTriggered = false;
    logger->verbose("Executing regular event starting from step {}", startStep);
    if (activeLevelDecoration) {
        engine->_globalEventMap.dump(eventId);
        interpreter.prepare(engine->_globalEventMap, eventId, canShowMessages);
    } else {
        engine->_localEventMap.dump(eventId);
        interpreter.prepare(engine->_localEventMap, eventId, canShowMessages);
    }

    if (interpreter.executeRegular(startStep)) {
        onMapLeave();
    }
}

bool npcDialogueEventProcessor(int eventId, int startStep) {
    if (!eventId) {
        return false;
    }

    EventInterpreter interpreter;

    logger->verbose("Executing NPC dialogue event starting from step {}", startStep);
    engine->_globalEventMap.dump(eventId);
    interpreter.prepare(engine->_globalEventMap, eventId, false);
    return interpreter.executeNpcDialogue(startStep);
}

std::string getEventHintString(int eventId) {
    return engine->_localEventMap.getHintString(eventId);
}

void registerEventTriggers() {
    onMapLoadTriggers.clear();
    onMapLoadTriggers = engine->_localEventMap.enumerateTriggers(EVENT_OnMapReload);
    onMapLeaveTriggers.clear();
    onMapLeaveTriggers = engine->_localEventMap.enumerateTriggers(EVENT_OnMapLeave);

    registerTimerTriggers(EVENT_OnLongTimer, &onLongTimerTriggers);
    registerTimerTriggers(EVENT_OnTimer, &onTimerTriggers);
}

void onMapLoad() {
    for (EventTrigger &triggers : onMapLoadTriggers) {
        eventProcessor(triggers.eventId, 0, false, triggers.eventStep + 1);
    }
}

void onMapLeave() {
    for (EventTrigger &triggers : onMapLeaveTriggers) {
        eventProcessor(triggers.eventId, 0, true, triggers.eventStep + 1);
    }
}

static void checkTimer(MapTimer &timer) {
    if (pParty->GetPlayingTime() >= timer.alarmTime) {
        eventProcessor(timer.eventId, 0, true, timer.eventStep + 1);
        if (timer.altInterval) {
            timer.alarmTime = pParty->GetPlayingTime() + timer.altInterval;
        } else {
            while (pParty->GetPlayingTime() >= timer.alarmTime) {
                timer.alarmTime += timer.interval;
            }
        }
    }
}

void onTimer() {
    if (pEventTimer->bPaused) {
        return;
    }

    for (MapTimer &timer : onTimerTriggers) {
        checkTimer(timer);
    }

    for (MapTimer &timer : onLongTimerTriggers) {
        checkTimer(timer);
    }
}