#pragma once

#include <span>
#include <utility>
#include <type_traits>
#include <vector>

#include "Engine/Objects/Actor.h"

#include "TestController.h"

class ActorTapeRecorder {
 public:
    explicit ActorTapeRecorder(TestController *controller);

    template<class Callback, class T = std::decay_t<std::invoke_result_t<Callback, const Actor &>>>
    TestTape<T> custom(int actorIndex, Callback callback) {
        return _controller->recordTape([actorIndex, callback = std::move(callback)] {
            return callback(actors()[actorIndex]);
        });
    }

    template<class Callback, class T = std::decay_t<std::invoke_result_t<Callback, const Actor &>>>
    TestMultiTape<T> custom(std::initializer_list<int> actorIndices, Callback callback) {
        return _controller->recordTape([actorIndices = std::vector(actorIndices), callback = std::move(callback)] {
            AccessibleVector<T> result;
            for (int actorIndex : actorIndices)
                result.push_back(callback(actors()[actorIndex]));
            return result;
        });
    }

    TestTape<int> countByState(AIState state);

    TestTape<int> countByBuff(ACTOR_BUFF_INDEX buff);

    TestMultiTape<int> indicesByState(AIState state);

    TestTape<int> hp(int actorIndex);

    TestMultiTape<int> hps(std::initializer_list<int> actorIndices);

    TestTape<AIState> aiState(int actorIndex);

    TestMultiTape<AIState> aiStates(std::initializer_list<int> actorIndices);

    TestTape<bool> hasBuff(int actorIndex, ACTOR_BUFF_INDEX buff);

 private:
    static std::span<Actor> actors();

 private:
    TestController *_controller = nullptr;
};
