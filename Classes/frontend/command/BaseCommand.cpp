//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "BaseCommand.h"
using namespace cocos2d;
BaseCommand::BaseCommand() {}
BaseCommand::~BaseCommand() {}
void BaseCommand::initialize(BaseBehaviour* behaviour, Layer* layer) { behaviour->onCreate(layer); }
void BaseCommand::initialize(BaseBehaviour* behaviour, Layer* layer, int depth) { behaviour->onCreate(layer, depth); }
void BaseCommand::initialize(BaseBehaviour* behaviour, Layer* layer, Position position) { behaviour->onCreate(layer, position); }
void BaseCommand::execute(BaseBehaviour* behaviour, float delta) { return; }
