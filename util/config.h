#pragma once

#include <list>
#include <tuple>

#include "util_def.h"

struct ConfigData;

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
    auto startPosition() { return std::tuple(start_pos_x_, start_pos_y_); };

  private:
    int map_size_w_{0};
    int map_size_h_{0};
    int origin_point_x_{0};
    int origin_point_y_{0};
    int pace_size_w_{0};
    int pace_size_h_{0};
    int interval_size_{0};
    int start_pos_x_{0};
    int start_pos_y_{0};

    std::list<ConfigData> config_data_list_;
};

struct ConfigData {
    UtilOrient orient;
    int        num;
};
