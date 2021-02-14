#pragma once

#include "config.h"
#include "util_def.h"

class Box;

class BoxCreator {
  public:
    BoxCreator(/* args */);
    ~BoxCreator();

    void setConfig(Config* config) { config_ = config; };

    bool createBox(UtilBoxType type, int x, int y, int num);

  private:
    Config* config_{nullptr};
};

class Box {
  public:
    Box();
    Box(int lux, int luy, int rlx, int rly);
    int LUX() { return lux_; };
    int LUY() { return luy_; };
    int RLX() { return rlx_; };
    int RLY() { return rly_; };
    int Width() { return lux_ - rlx_; };
    int Height() { return luy_ - rly_; };

    void setLUX(int lux) { lux_ = llx_ = lux; };
    void setLUY(int luy) { luy_ = ruy_ = luy; };
    void setRLX(int rlx) { rlx_ = rux_ = rlx; };
    void setRLY(int rly) { rly_ = lly_ = rly; };

  private:
    int llx_{0};
    int lly_{0};
    int lux_{0};
    int luy_{0};
    int rlx_{0};
    int rly_{0};
    int rux_{0};
    int ruy_{0};
};