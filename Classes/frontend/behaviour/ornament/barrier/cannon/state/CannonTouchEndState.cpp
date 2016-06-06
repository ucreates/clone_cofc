//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#include "CannonTouchEndState.h"

// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
#include "GeographicDepth.h"
#include "BarrierBehaviourType.h"

// notify
#include "Notifier.h"
#include "NotifyMessage.h"

// utility
#include "Degree.h"
#include "Figure.h"
#include "Vector2D.h"
#include "Random.h"
#include "Alpha.h"

using namespace cocos2d;

CannonTouchEndState::CannonTouchEndState() {}

CannonTouchEndState::~CannonTouchEndState() {}

void CannonTouchEndState::create(Parameter* parameter) {
    Vec2 pos = parameter->get<Vec2>("touchPosition");
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicNode* node = gateway->findByPosition(pos);
    if (NULL == node || BarrierBehaviourType::None != node->type) {
        return;
    }

    pos = node->position;

    node->type = BarrierBehaviourType::Cannon;
    this->owner->setGeographicNode(node);
    std::vector<GeographicNode*> nodeVector;
    nodeVector.push_back(node);
    this->owner->setGeographicNodeVector(nodeVector);

    Parameter notifyParam;
    std::vector<int> idVector;
    idVector.push_back(node->geographicId);
    notifyParam.set<std::vector<int>>("parameter", idVector);
    Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Node);
    Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Start, &notifyParam);

    GLubyte alpha = Alpha::NOT_ALPHA;

    AnimatorAsset* anime = (AnimatorAsset*)this->owner->getAsset("anime");
    anime->transform(pos);
    anime->transform(node->depth + GeographicDepth::ORNAMENT_TOUCH_DEPTH);
    anime->transform(alpha);

    AnimatorAsset* texture = (AnimatorAsset*)this->owner->getAsset("texture");
    texture->transform(pos);
    texture->transform(node->depth + GeographicDepth::ORNAMENT_TOUCH_DEPTH - 1);
    texture->transform(alpha);

    Notifier::getInstance()->notify(NotifyMessage::Geography_Editor_Reset);
    return;
}
