//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LoadingUILoadingState_h
#define LoadingUILoadingState_h
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "FiniteState.h"
#include "LoadingUIBehaviour.h"
class LoadingUIBehaviour;
class LoadingUILoadingState : public FiniteState<LoadingUIBehaviour> {
   public:
    LoadingUILoadingState();
    virtual ~LoadingUILoadingState();
    void create() override;
    void update(float delta) override;
    void reset() override;
   private:
    TimeLine* statementTimeLine;
    cocos2d::ui::LoadingBar* loadingBar;
    cocos2d::ui::Text* loadingLabel;
    cocos2d::ui::Text* tutorialLabel;
};
#endif
