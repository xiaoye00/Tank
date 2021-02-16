#pragma once

#include <list>
#include <map>
#include <string>
#include <tuple>

#include "box_creator.h"
#include "util_def.h"

class Config {
  public:
    Config();
    ~Config();
    bool loadDesign(char* path);
    auto test() { return 1; };
    auto mapSize() { return std::tuple(map_size_w_, map_size_h_); };
    auto originPoint() { return std::tuple(origin_point_x_, origin_point_y_); };
    auto paceSize() { return std::tuple(pace_size_w_, pace_size_h_); };
    auto intervalSize() { return interval_size_; };
    auto getPaceBoxes() { return pace_box_list_; };
    auto mallSize() { return std::tuple(mall_size_w_, mall_size_h_); };
    auto shopSize() { return std::tuple(mall_size_w_, mall_size_h_); };
    auto defaltBuildingSize() { return std::tuple(defalt_building_size_w_, defalt_building_size_h_); };

  private:
    int            map_size_w_{0};
    int            map_size_h_{0};
    int            origin_point_x_{0};
    int            origin_point_y_{0};
    int            pace_size_w_{0};
    int            pace_size_h_{0};
    int            interval_size_{0};
    int            mall_size_w_{0};
    int            mall_size_h_{0};
    int            shop_size_w_{0};
    int            shop_size_h_{0};
    int            defalt_building_size_w_;
    int            defalt_building_size_h_;
    std::list<Box> pace_box_list_;
};
