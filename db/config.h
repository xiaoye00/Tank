#pragma once

#include "db.h"

class Config {
  public:
    Config();
    ~Config();
    bool  loadDesign(const char* path);

};
