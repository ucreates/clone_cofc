//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// stl
#include <vector>

// service
#include "BaseAssembler.h"
#include "TAssetTable.h"

template <class T>
BaseAssembler<T>::BaseAssembler() {}

template <class T>
BaseAssembler<T>::~BaseAssembler() {}

template <class T>
std::vector<T> BaseAssembler<T>::writeToVector() {
    std::vector<T> ret;
    return ret;
}

template class BaseAssembler<std::string>;
template class BaseAssembler<TAssetTable>;
