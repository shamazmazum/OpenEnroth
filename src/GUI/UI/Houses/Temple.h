#pragma once

#include <vector>

#include "GUI/UI/UIHouses.h"
#include "GUI/UI/UIHouseEnums.h"
#include "Engine/Objects/Character.h"

class GUIWindow_Temple : public GUIWindow_House {
 public:
    explicit GUIWindow_Temple(HouseId houseId);
    virtual ~GUIWindow_Temple() {}

    virtual void houseDialogueOptionSelected(DIALOGUE_TYPE option) override;
    virtual void houseSpecificDialogue() override;
    virtual std::vector<DIALOGUE_TYPE> listDialogueOptions() override;
    virtual void updateDialogueOnEscape() override;
    virtual void playHouseGoodbyeSpeech() override;

 protected:
    void mainDialogue();
    void healDialogue();
    void donateDialogue();

    /**
     * @offset 0x4B6FF9
     */
    bool isPlayerHealableByTemple(const Character &player) const;

 private:
    std::vector<int> _templeSpellCounter;
};
