#pragma once

#include <vector>

#include "GUI/UI/UIHouses.h"
#include "GUI/UI/UIHouseEnums.h"

class GUIWindow_Tavern : public GUIWindow_House {
 public:
    explicit GUIWindow_Tavern(HouseId houseId) : GUIWindow_House(houseId) {}
    virtual ~GUIWindow_Tavern() {}

    virtual void houseDialogueOptionSelected(DIALOGUE_TYPE option) override;
    virtual void houseSpecificDialogue() override;
    virtual std::vector<DIALOGUE_TYPE> listDialogueOptions() override;
    virtual void updateDialogueOnEscape() override;

 protected:
    void mainDialogue();
    void arcomageMainDialogue();
    void arcomageRulesDialogue();
    void arcomageVictoryCondDialogue();
    void arcomageResultDialogue();
    void restDialogue();
    void buyFoodDialogue();
};
