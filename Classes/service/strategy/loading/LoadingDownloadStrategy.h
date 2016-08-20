//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LoadingDownloadStrategy_h
#define LoadingDownloadStrategy_h
// service
#include "BaseStrategy.h"
class LoadingDownloadStrategy : public BaseStrategy {
   public:
    LoadingDownloadStrategy();
    virtual ~LoadingDownloadStrategy();
    Response get(Parameter* parameter = NULL) override;
    Response request(Parameter* parameter = NULL) override;
    Response update(Parameter* parameter = NULL) override;
};
#endif
