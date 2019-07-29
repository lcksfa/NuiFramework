#pragma once

#include "resource.h"

/** @class MainThread
 * @brief UI thread extends nbase::FrameworkThread
 * @copyright (c) 2015, NetEase Inc. All rights reserved
 * @author towik
 * @date 2015/1/1
 */
class MainThread : public nbase::FrameworkThread {
  public:
    MainThread() : nbase::FrameworkThread("MainThread") {}
    virtual ~MainThread() {}

  private:
    virtual void Init() override;

    virtual void Cleanup() override;
};
