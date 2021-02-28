#include "building.h"

#include "player.h"

namespace tank {
Building::Building() {
}

Building::~Building() {
}

void Building::setOwner(Player* player) {
    owner_ = player;
}

int Building::getToll() {
    switch (box_->Type()) {
    case BoxType::kMall:
        switch (level_) {
        case 0:
            return 0;
            break;
        case 1:
            return mall_toll_base_ / 4;
            break;
        case 2:
            return mall_toll_base_ / 2;
            break;
        case 3:
            return mall_toll_base_;
            break;
        case 4:
            return mall_toll_base_ * 1.2;
            break;
        case 5:
            return mall_toll_base_ * 1.5;
            break;

        default:
            break;
        }

        break;
    case BoxType::kShop:
        switch (level_) {
        case 0:
            return 0;
            break;
        case 1:
            return shop_toll_base_ / 4;
            break;
        case 2:
            return shop_toll_base_ / 2;
            break;
        case 3:
            return shop_toll_base_;
            break;
        case 4:
            return shop_toll_base_ * 1.2;
            break;
        case 5:
            return shop_toll_base_ * 1.5;
            break;

        default:
            break;
        }

        break;
    case BoxType::kDefaltBuilding:
        switch (level_) {
        case 0:
            return 0;
            break;
        case 1:
            return defalt_toll_base_ / 4;
            break;
        case 2:
            return defalt_toll_base_ / 2;
            break;
        case 3:
            return defalt_toll_base_;
            break;
        case 4:
            return defalt_toll_base_ * 1.2;
            break;
        case 5:
            return defalt_toll_base_ * 1.5;
            break;

        default:
            break;
        }

        break;
    case BoxType::kNull:
        return 0;
        break;
    default:
        break;
    }
}

int Building::getPice() {
    auto level = level_ + 1;
    switch (box_->Type()) {
    case BoxType::kMall:
        switch (level) {
        case 0:
            return 0;
            break;
        case 1:
            return mall_toll_base_;
            break;
        case 2:
            return mall_toll_base_ * 2;
            break;
        case 3:
            return mall_toll_base_ * 3;
            break;
        case 4:
            return mall_toll_base_ * 4;
            break;
        case 5:
            return mall_toll_base_ * 5;
            break;

        default:
            break;
        }

        break;
    case BoxType::kShop:
        switch (level) {
        case 0:
            return 0;
            break;
        case 1:
            return shop_toll_base_;
            break;
        case 2:
            return shop_toll_base_ * 2;
            break;
        case 3:
            return shop_toll_base_ * 3;
            break;
        case 4:
            return shop_toll_base_ * 4;
            break;
        case 5:
            return shop_toll_base_ * 5;
            break;

        default:
            break;
        }

        break;
    case BoxType::kDefaltBuilding:
        switch (level) {
        case 0:
            return 0;
            break;
        case 1:
            return defalt_toll_base_;
            break;
        case 2:
            return defalt_toll_base_ * 2;
            break;
        case 3:
            return defalt_toll_base_ * 3;
            break;
        case 4:
            return defalt_toll_base_ * 4;
            break;
        case 5:
            return defalt_toll_base_ * 5;
            break;

        default:
            break;
        }

        break;
    case BoxType::kNull:
        return 0;
        break;
    default:
        break;
    }
}

int Building::max_level_        = 0;
int Building::mall_toll_base_   = 0;
int Building::shop_toll_base_   = 0;
int Building::defalt_toll_base_ = 0;
int Building::null_tool_base_   = 0;
;

} // namespace tank