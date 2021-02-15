#pragma once

#include <tuple>

#include "config.h"
#include "util_def.h"

class Box;
class Point;

class BoxCreator {
  public:
    BoxCreator(/* args */);
    ~BoxCreator();

    void setConfig(Config* config) { config_ = config; };

    Box createBox(UtilBoxType type, int x, int y);

  private:
    Config* config_{nullptr};
};

class Point {
  public:
    Point(){};
    Point(int x, int y) {
        x_ = x;
        y_ = y;
    };
    ~Point(){};

    int  rx() { return x_; };
    int  ry() { return y_; };
    void setX(int x) { x_ = x; };
    void setY(int y) { y_ = y; };

  private:
    int x_{0};
    int y_{0};
};

class Box {
  public:
    Box(){};
    ~Box(){};
    Box(int lux, int luy, int rlx, int rly) {
        setLUX(lux);
        setLUY(luy);
        setRLX(rlx);
        setRLY(rly);
    };
    Box(Point center_point, int w, int h) {
        setLUX(center_point.rx() - w / 2);
        setLUY(center_point.ry() - h / 2);
        setRLX(center_point.rx() + w / 2);
        setRLY(center_point.ry() + h / 2);
    };
    int  LUX() { return lux_; };
    int  LUY() { return luy_; };
    int  RLX() { return rlx_; };
    int  RLY() { return rly_; };
    int  Width() { return -lux_ + rlx_; };
    int  Height() { return -luy_ + rly_; };
    auto getCenterPoint() {
        auto center_x = (llx_ + rlx_) / 2;
        auto center_y = (luy_ + lly_) / 2;
        return Point(center_x, center_y);
    };
    auto getNextBoxCenter(UtilOrient orient) {
        auto center_point = getCenterPoint();
        switch (orient) {
        case UtilOrient::kToRight: {
            center_point.setX(center_point.rx() + Width());
            return center_point;
        } break;
        case UtilOrient::kToDown:
            center_point.setY(center_point.ry() + Height());
            return center_point;
            break;
        case UtilOrient::kToLeft:
            center_point.setX(center_point.rx() - Width());
            return center_point;
            break;
        case UtilOrient::kToUp:
            center_point.setY(center_point.ry() - Height());
            return center_point;
            break;
        default:
            return center_point;
            break;
        }
    };

    auto getNextBox(UtilOrient orient) {
        auto point = getNextBoxCenter(orient);
        return Box(point, Width(), Height());
    };

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
