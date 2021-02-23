#pragma once

#include <list>
#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "box.h"
#include "db_def.h"
#include "player.h"
namespace Tank {
class DB {
  public:
    ~DB();

    static DB* getInstance() {
        if (!inst_) {
            inst_ = new DB;
        }
        return inst_;
    }

    auto setMapSize(int w, int h) { map_size_w_ = w, map_size_h_ = h; };
    auto MapSize() { return std::tuple(map_size_w_, map_size_h_); };
    auto setOriginPoint(int x, int y) { origin_point_x_ = x, origin_point_y_ = y; };
    auto OriginPoint() { return std::tuple(origin_point_x_, origin_point_y_); };
    auto setPaceSize(int w, int h) { pace_size_w_ = w, pace_size_h_ = h; };
    auto PaceSize() { return std::tuple(pace_size_w_, pace_size_h_); };
    auto setIntervalSize(int size) { interval_size_ = size; };
    auto IntervalSize() { return interval_size_; };

    auto setMallSize(int w, int h) { mall_size_w_ = w, mall_size_h_ = h; };
    auto MallSize() { return std::tuple(mall_size_w_, mall_size_h_); };
    auto setShopSize(int w, int h) { shop_size_w_ = w, shop_size_h_ = h; };
    auto ShopSize() { return std::tuple(shop_size_w_, shop_size_h_); };
    auto setDefaltBuildingSize(int w, int h) { defalt_building_size_w_ = w, defalt_building_size_h_ = h; };
    auto DefaltBuildingSize() { return std::tuple(defalt_building_size_w_, defalt_building_size_h_); };

    auto    appendPaceBox(Box* box) { pace_box_list_.push_back(box); };
    auto    getPaceBoxes() { return &pace_box_list_; };
    int     getNumPaces() { return pace_box_list_.size(); };
    auto    appendBuildingBox(Box* box) { building_box_list_.push_back(box); };
    auto    getBuildingBoxes() { return &building_box_list_; };
    auto    appendPlayer(Player* player) { player_list_.push_back(player); };
    auto    getPlayers() { return &player_list_; };
    Player* getPlayerByID(int ID);
    Player* getCurrentPlayer();
    auto    getNumPlayers() { return player_list_.size(); };

  private:
    int                  map_size_w_{0};
    int                  map_size_h_{0};
    int                  origin_point_x_{0};
    int                  origin_point_y_{0};
    int                  pace_size_w_{0};
    int                  pace_size_h_{0};
    int                  interval_size_{0};
    int                  mall_size_w_{0};
    int                  mall_size_h_{0};
    int                  shop_size_w_{0};
    int                  shop_size_h_{0};
    int                  defalt_building_size_w_;
    int                  defalt_building_size_h_;
    std::vector<Box*>    pace_box_list_;
    std::vector<Box*>    building_box_list_;
    std::vector<Player*> player_list_;

    static DB* inst_;
    DB(/* args */){};
};
} // namespace Tank
