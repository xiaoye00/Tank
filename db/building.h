#pragma once
#include "box.h"

namespace tank {

class Player;

class Building {
  public:
    Building();
    ~Building();

    auto setBox(Box* box) {
        box_ = box;
        id_  = box_->ID();
    };
    auto getBox() { return box_; };
    void setOwner(Player* player);
    auto getOwner() { return owner_; };
    auto ID() { return id_; };
    auto setLevel(int level) { level_ = level; };
    auto Level() { return level_; };
    auto getBuildingType() { return box_->Type(); };
    int  getToll();
    int  getPice();

    static void setMaxBuildingLevel(int max_level) { max_level_ = max_level; };
    static int  MaxBuildingLevel() { return max_level_; };
    static void setMallTollBase(int mall_toll_base) { mall_toll_base_ = mall_toll_base; };
    static int  MallTollBase() { return mall_toll_base_; };
    static void setShopTollBase(int shop_toll_base) { shop_toll_base_ = shop_toll_base; };
    static int  ShopTollBase() { return shop_toll_base_; };
    static void setDefaltTollBase(int defalt_toll_base) { defalt_toll_base_ = defalt_toll_base; };
    static int  DefaltTollBas() { return defalt_toll_base_; };
    static void setNullTollBase(int null_tool_base) { null_tool_base_ = null_tool_base; };
    static int  NullTollBase() { return null_tool_base_; };

  private:
    Box*       box_{nullptr};
    Player*    owner_{nullptr};
    int        id_{0};
    int        level_{0};
    static int max_level_;
    static int mall_toll_base_;
    static int shop_toll_base_;
    static int defalt_toll_base_;
    static int null_tool_base_;
};

} // namespace tank