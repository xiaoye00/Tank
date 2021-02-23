#include "box.h"

#include "config.h"
#include "transform.h"
#include "building.h"
namespace Tank {
BoxCreator::BoxCreator(/* args */) {
}

BoxCreator::~BoxCreator() {
}
/**
 * BoxCreator 
 * 
 * @param  {UtilBoxType} type : 
 * @param  {int} x            :  center x
 * @param  {int} y            :  center y
 * @return {Box}              : 
 */
Box* BoxCreator::createBox(BoxType type, int x, int y) {
    switch (type) {
    case BoxType::kPace: {
        auto [w, h] = DB::getInstance()->PaceSize();
        auto box    = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    }
    case BoxType::kMall: {
        auto [w, h] = DB::getInstance()->MallSize();
        auto box    = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    } break;
    case BoxType::kShop: {
        auto [w, h] = DB::getInstance()->ShopSize();
        auto box    = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    } break;
    case BoxType::kDefaltBuilding: {
        auto [w, h] = DB::getInstance()->DefaltBuildingSize();
        auto box    = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    } break;

    default:
        break;
    }
}

Point BoxCreator::deduceBoxCenterPoint(PlacementOrient orient, BoxType box_type, Point anchor_point) {
    auto center_point     = anchor_point;
    auto [pace_w, pace_h] = DB::getInstance()->PaceSize();
    switch (orient) {
    case PlacementOrient::kToRight: {
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
    } break;
    case PlacementOrient::kToDown:
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;

        default:
            break;
        }
        break;
    case PlacementOrient::kToLeft:
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
        break;
    case PlacementOrient::kToUp:
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);

        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
        break;
    default:
        break;
    }

    return center_point;
};

Point BoxCreator::deduceNextAnchorPoint(PlacementOrient orient, BoxType box_type, Point anchor_point) {
    auto center_point = anchor_point;

    switch (orient) {
    case PlacementOrient::kToRight: {
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case BoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() + w);
        } break;

        default:
            break;
        }
    } break;
    case PlacementOrient::kToDown:
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case BoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() + h);
        } break;

        default:
            break;
        }
        break;
    case PlacementOrient::kToLeft:
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case BoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() - w);
        } break;

        default:
            break;
        }
        break;
    case PlacementOrient::kToUp:
        switch (box_type) {
        case BoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case BoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setY(center_point.ry() - h);

        } break;
        case BoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case BoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case BoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() - h);
        } break;

        default:
            break;
        }
        break;
    default:
        break;
    }

    return center_point;
}

void BoxCreator::associateBuildingBox(PlacementOrient orient, Building* building) {
    auto box = building->getBox();
    auto point            = box->getCenterPoint();
    auto [pace_w, pace_h] = DB::getInstance()->PaceSize();
    switch (orient) {
    case PlacementOrient::kToRight: {
        auto start_x    = point.rx() - box->Width() / 2;
        auto end_x      = point.rx() + box->Width() / 2;
        auto anchor_y   = point.ry() + box->Height() / 2 + DB::getInstance()->IntervalSize() + pace_h / 2;
        auto paces = DB::getInstance()->getPaces();
        for (auto& pace : *paces) {
            auto pace_point = pace->getBox()->getCenterPoint();
            if (pace_point.rx() >= start_x && pace_point.rx() <= end_x && pace_point.ry() == anchor_y) {
                pace->setAssociateBuilding(building);
            }
        }

    } break;
    case PlacementOrient::kToDown: {
        auto anchor_x   = point.rx() - box->Width() / 2 - DB::getInstance()->IntervalSize() - pace_w / 2;
        auto start_y    = point.ry() - box->Height() / 2;
        auto end_y      = point.ry() + box->Height() / 2;
        auto paces = DB::getInstance()->getPaces();

        for (auto& pace : *paces) {
            auto point = pace->getBox()->getCenterPoint();
            if (point.ry() >= start_y && point.ry() <= end_y && point.rx() == anchor_x) {
                pace->setAssociateBuilding(building);
            }
        }
    } break;
    case PlacementOrient::kToLeft: {
        auto start_x    = point.rx() - box->Width() / 2;
        auto end_x      = point.rx() + box->Width() / 2;
        auto anchor_y   = point.ry() + box->Height() / 2 + DB::getInstance()->IntervalSize() + pace_h / 2;
        auto paces = DB::getInstance()->getPaces();
        for (auto& pace : *paces) {
            auto pace_point = pace->getBox()->getCenterPoint();
            if (pace_point.rx() >= start_x && pace_point.rx() <= end_x && pace_point.ry() == anchor_y) {
                pace->setAssociateBuilding(building);
            }
        }
    } break;
    case PlacementOrient::kToUp: {
        auto anchor_x = point.rx() + box->Width() / 2 + DB::getInstance()->IntervalSize() + pace_w / 2;
        auto start_y  = point.ry() - box->Height() / 2;
        auto end_y    = point.ry() + box->Height() / 2;

        auto paces = DB::getInstance()->getPaces();
        for (auto& pace : *paces) {
            auto point = pace->getBox()->getCenterPoint();
            if (point.ry() >= start_y && point.ry() <= end_y && point.rx() == anchor_x) {
                pace->setAssociateBuilding(building);
            }
        }
    } break;
    }
}

int BoxCreator::global_index_ = 0;
} // namespace Tank
