//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "Bouncy.h"
Bouncy::Bouncy() : Bouncy(1.0f) {}
Bouncy::Bouncy(float verocity) {
    this->verocity = 0;
    this->originVerocity = 0;
    this->seedVerocity = verocity;
    this->e = 0.5f;
    this->gravity = 0.098f;
}
void Bouncy::initialize() {
    this->originVerocity = this->seedVerocity;
    this->verocity = this->seedVerocity;
}
float Bouncy::execute() {
    this->verocity -= this->gravity;
    if (this->verocity <= Bouncy::MIN_VEROCITY_RATE) {
        this->originVerocity *= this->e;
        this->verocity = this->originVerocity;
    }
    return this->verocity;
}
void Bouncy::setVerocity(float verocity) { this->seedVerocity = verocity; }
