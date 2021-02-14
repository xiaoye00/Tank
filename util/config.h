#pragma once

#include <list>

#include "util_def.h"


struct ConfigData;

class Config {
  public:
    Config();
    ~Config();
    bool loadDesign(char* path);

  private:
    int map_size_w_{0};
    int map_size_h_{0};
    int origin_point_x_{0};
    int origin_point_y_{0};
    int pace_size_w{0};
    int pace_size_h{0};

    std::list<ConfigData> config_data_list_;
};

struct ConfigData {
    UtilOrient orient;
    int        num;
};
