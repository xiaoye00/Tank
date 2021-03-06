#pragma once

#include <list>
#include <tuple>
#include "db_def.h"

namespace tank {
class Box;
class Point;
class Config;
class Building;

class BoxCreator {
  public:
    BoxCreator(/* args */);
    ~BoxCreator();

    void setConfig(Config* config) { config_ = config; };

    Box* createBox(BoxType type, int x, int y);

    Point deduceBoxCenterPoint(PlacementOrient orient, BoxType box_type, Point anchor_point);
    Point deduceNextAnchorPoint(PlacementOrient orient, BoxType box_type, Point anchor_point);
    void  associateBuildingBox(PlacementOrient orient, Building* box);

  private:
    Config*    config_{nullptr};
    static int global_index_;
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
    int  Width() const { return -lux_ + rlx_; };
    int  Height() const { return -luy_ + rly_; };
    void setID(int index) { id_ = index; };
    int  ID() { return id_; };
    auto getCenterPoint() {
        auto center_x = (llx_ + rlx_) / 2;
        auto center_y = (luy_ + lly_) / 2;
        return Point(center_x, center_y);
    };

    void  setLUX(int lux) { lux_ = llx_ = lux; };
    void  setLUY(int luy) { luy_ = ruy_ = luy; };
    void  setRLX(int rlx) { rlx_ = rux_ = rlx; };
    void  setRLY(int rly) { rly_ = lly_ = rly; };
    void  setType(BoxType type) { type_ = type; };
    auto  Type() { return type_; };

  private:
    int            llx_{0};
    int            lly_{0};
    int            lux_{0};
    int            luy_{0};
    int            rlx_{0};
    int            rly_{0};
    int            rux_{0};
    int            ruy_{0};
    int            id_{0};
    int            associateID_{0};
    BoxType    type_;
};
} // namespace Tank
