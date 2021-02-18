#pragma once

#include <list>
#include <tuple>
#include "db_def.h"

class Box;
class Point;
class Config;

class BoxCreator {
  public:
    BoxCreator(/* args */);
    ~BoxCreator();

    void setConfig(Config* config) { config_ = config; };

    Box createBox(UtilBoxType type, int x, int y);

    Point deduceBoxCenterPoint(UtilOrient orient, UtilBoxType box_type, Point anchor_point);
    Point deduceNextAnchorPoint(UtilOrient orient, UtilBoxType box_type, Point anchor_point);
    void  associateBuildingBox(UtilOrient orient, Box box);

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
    void setIndex(int index) { index_ = index; };
    int  Index() { return index_; };
    auto getCenterPoint() {
        auto center_x = (llx_ + rlx_) / 2;
        auto center_y = (luy_ + lly_) / 2;
        return Point(center_x, center_y);
    };

    void  setLUX(int lux) { lux_ = llx_ = lux; };
    void  setLUY(int luy) { luy_ = ruy_ = luy; };
    void  setRLX(int rlx) { rlx_ = rux_ = rlx; };
    void  setRLY(int rly) { rly_ = lly_ = rly; };
    void  setAssociateBox(int index) { test_list.push_back(index); };
    auto& getAssociateBoxes() { return test_list; };
    void  setType(UtilBoxType type) { type_ = type; };
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
    int            index_{0};
    int            associateID_{0};
    UtilBoxType    type_;
    std::list<int> test_list;
};
