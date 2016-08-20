//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "CannonSearchState.h"
// behaviour
#include "BehaviourCollection.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
// notify
#include "Notifier.h"
#include "NotifyMessage.h"
// utility
#include "Distance.h"
#include "Degree.h"
#include "Figure.h"
#include "Vector2D.h"
#include "Random.h"
#include "Position.h"
CannonSearchState::CannonSearchState() {
    // frame
    this->counterTimeLine = new TimeLine();
    this->lastTargetDegree = 0.0f;
    this->finishSearch = false;
    this->finishCalc = false;
}
CannonSearchState::~CannonSearchState() { CC_SAFE_DELETE(this->counterTimeLine); }
void CannonSearchState::create() {
    this->finishCalc = false;
    this->finishSearch = false;
    this->target = NULL;
    this->asset = (AnimatorAsset*)this->owner->getAsset("anime");
    this->search();
    return;
}
void CannonSearchState::update(float delta) {
    if (false == this->finishSearch) {
        return;
    } else {
        if (false == this->finishCalc) {
            bool ret = this->calcDegree();
            if (false == ret) {
                this->owner->getStateMachine()->change("search");
                return;
            }
        }
    }
    if (this->counterTimeLine->getFrame() > this->maxFrameNumber) {
        Parameter parameter;
        int degree = (int)this->lastTargetDegree;
        parameter.set<int>("degree", degree);
        parameter.set<float>("shotDegree", this->lastTargetDegree);
        this->owner->getStateMachine()->change("attack", &parameter);
        return;
    }
    int currentFrame = this->frame->getFrame();
    if (currentFrame > CannonSearchState::MAX_FRAME_NUMBER) {
        this->frame->reset();
        currentFrame = 0;
    } else if (currentFrame < 0) {
        this->frame->reset(CannonSearchState::MAX_FRAME_NUMBER, 0.0f);
        currentFrame = CannonSearchState::MAX_FRAME_NUMBER;
    }
    this->asset->pause(currentFrame);
    this->frame->setFrame(1 * this->searchDirection);
    this->counterTimeLine->setFrame(1);
    return;
}
void CannonSearchState::search() {
    std::thread thread = std::thread([this]() {
        Transform ctrfm = this->asset->getTransform();
        Position cpos = ctrfm.getPosition();
        BehaviourCollection* collection = BehaviourCollection::getInstance();
        std::vector<BaseBehaviour*>* behaviourVector = collection->getBehaviourVector("unit");
        for (std::vector<BaseBehaviour*>::iterator it = behaviourVector->begin(); it != behaviourVector->end(); it++) {
            BaseBehaviour* behaviour = (BaseBehaviour*)(*it);
            std::string type = behaviour->getProperty()->getType();
            BaseUnitBehaviour* unit = (BaseUnitBehaviour*)behaviour;
            BaseRenderAsset* asset = (BaseRenderAsset*)unit->getAsset("anime");
            Transform ttrfm = asset->getTransform();
            Position tpos = ttrfm.getPosition();
            int distance = Distance::create(cpos, tpos);
            if (distance < CannonSearchState::MOST_SHORTEST_DISTANCE) {
                this->target = unit;
                break;
            }
        }
        this->finishSearch = true;
    });
    thread.detach();
    return;
}
bool CannonSearchState::calcDegree() {
    if (NULL == this->target) {
        return false;
    }
    BaseRenderAsset* unitAsset = (BaseRenderAsset*)this->target->getAsset("anime");
    if (NULL == unitAsset) {
        return false;
    }
    Transform ttrfm = unitAsset->getTransform();
    Position tpos = ttrfm.getPosition();
    Transform entity = this->asset->getTransform();
    Position cpos = entity.getPosition();
    // start frame
    float startDegree = this->lastTargetDegree;
    int startFrame = startDegree / 10;
    // end frame
    this->lastTargetDegree = Degree::create(cpos, tpos, true);
    int endFrame = this->lastTargetDegree / 10;
    // frame count
    float product = Vector2D::product(startDegree, this->lastTargetDegree);
    if (0 <= product) {
        this->searchDirection = 1;
        if (endFrame < startFrame) {
            this->maxFrameNumber = CannonSearchState::MAX_FRAME_NUMBER + endFrame - startFrame + 2;
        } else {
            this->maxFrameNumber = endFrame - startFrame + 1;
        }
    } else {
        this->searchDirection = -1;
        if (startFrame < endFrame) {
            this->maxFrameNumber = CannonSearchState::MAX_FRAME_NUMBER - (endFrame - startFrame) + 2;
        } else {
            this->maxFrameNumber = -1 * (endFrame - startFrame) + 1;
        }
    }
    this->counterTimeLine->reset();
    // asset
    this->asset->pause(startFrame);
    this->frame->reset(startFrame, 0.0f);
    this->finishCalc = true;
    return true;
}
