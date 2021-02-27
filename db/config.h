#pragma once

#include "db.h"
namespace tank {
class Config {
  public:
    Config();
    ~Config();
    bool loadDesign(const char* path);
};
} // namespace Tank
