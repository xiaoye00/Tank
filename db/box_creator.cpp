#include "box_creator.h"

#include "config.h"
#include "transform.h"

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
Box* BoxCreator::createBox(UtilBoxType type, int x, int y) {
    switch (type) {
    case UtilBoxType::kPace: {
        auto [w, h] = DB::getInstance()->PaceSize();
        auto box = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    }
    case UtilBoxType::kMall: {
        auto [w, h] = DB::getInstance()->MallSize();
        auto box = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    } break;
    case UtilBoxType::kShop: {
        auto [w, h] = DB::getInstance()->ShopSize();
        auto box = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    } break;
    case UtilBoxType::kDefaltBuilding: {
        auto [w, h] = DB::getInstance()->DefaltBuildingSize();
        auto box = new Box(Point(x, y), w, h);
        box->setIndex(global_index_++);
        box->setType(type);
        return box;
    } break;

    default:
        break;
    }
}

Point BoxCreator::deduceBoxCenterPoint(UtilOrient orient, UtilBoxType box_type, Point anchor_point) {
    auto center_point     = anchor_point;
    auto [pace_w, pace_h] = DB::getInstance()->PaceSize();
    switch (orient) {
    case UtilOrient::kToRight: {
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
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
    case UtilOrient::kToDown:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
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
    case UtilOrient::kToLeft:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
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
    case UtilOrient::kToUp:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);

        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - DB::getInstance()->IntervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
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

Point BoxCreator::deduceNextAnchorPoint(UtilOrient orient, UtilBoxType box_type, Point anchor_point) {
    auto center_point = anchor_point;

    switch (orient) {
    case UtilOrient::kToRight: {
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() + w);
        } break;

        default:
            break;
        }
    } break;
    case UtilOrient::kToDown:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() + h);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToLeft:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setX(center_point.rx() - w);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToUp:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = DB::getInstance()->PaceSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = DB::getInstance()->MallSize();
            center_point.setY(center_point.ry() - h);

        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = DB::getInstance()->ShopSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = DB::getInstance()->DefaltBuildingSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kNull: {
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

void BoxCreator::associateBuildingBox(UtilOrient orient, Box* box) {
    auto point            = box->getCenterPoint();
    auto [pace_w, pace_h] = DB::getInstance()->PaceSize();
    switch (orient) {
    case UtilOrient::kToRight: {
        auto                              start_x    = point.rx() - box->Width() / 2;
        auto                              end_x      = point.rx() + box->Width() / 2;
        auto                              anchor_y   = point.ry() + box->Height() / 2 + DB::getInstance()->IntervalSize() + pace_h / 2;
        decltype(DB::getInstance()->getPaceBoxes()) pace_boxes = DB::getInstance()->getPaceBoxes();
        for (auto& pace_box : pace_boxes) {
            auto pace_point = pace_box->getCenterPoint();
            if (pace_point.rx() >= start_x && pace_point.rx() <= end_x && pace_point.ry() == anchor_y) {
                pace_box->setAssociateBox(box->Index());
            }
        }

    } break;
    case UtilOrient::kToDown: {
        auto  anchor_x   = point.rx() - box->Width() / 2 - DB::getInstance()->IntervalSize() - pace_w / 2;
        auto  start_y    = point.ry() - box->Height() / 2;
        auto  end_y      = point.ry() + box->Height() / 2;
        auto& pace_boxes = DB::getInstance()->getPaceBoxes();

        for (auto& pace_box : pace_boxes) {
            auto point = pace_box->getCenterPoint();
            if (point.ry() >= start_y && point.ry() <= end_y && point.rx() == anchor_x) {
                pace_box->setAssociateBox(box->Index());
            }
        }
    } break;
    case UtilOrient::kToLeft: {
        auto                              start_x    = point.rx() - box->Width() / 2;
        auto                              end_x      = point.rx() + box->Width() / 2;
        auto                              anchor_y   = point.ry() + box->Height() / 2 + DB::getInstance()->IntervalSize() + pace_h / 2;
        decltype(DB::getInstance()->getPaceBoxes()) pace_boxes = DB::getInstance()->getPaceBoxes();
        for (auto& pace_box : pace_boxes) {
            auto pace_point = pace_box->getCenterPoint();
            if (pace_point.rx() >= start_x && pace_point.rx() <= end_x && pace_point.ry() == anchor_y) {
                pace_box->setAssociateBox(box->Index());
            }
        }
    } break;
    case UtilOrient::kToUp: {
        auto anchor_x = point.rx() + box->Width() / 2 + DB::getInstance()->IntervalSize() + pace_w / 2;
        auto start_y  = point.ry() - box->Height() / 2;
        auto end_y    = point.ry() + box->Height() / 2;

        auto& pace_boxes = DB::getInstance()->getPaceBoxes();
        for (auto& pace_box : pace_boxes) {
            auto point = pace_box->getCenterPoint();
            if (point.ry() >= start_y && point.ry() <= end_y && point.rx() == anchor_x) {
                pace_box->setAssociateBox(box->Index());
            }
        }
    } break;
    }
}

int BoxCreator::global_index_ = 0;
