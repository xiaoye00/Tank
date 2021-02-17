#include "box_creator.h"

#include "config.h"

BoxCreator::BoxCreator(/* args */) {
}

BoxCreator::~BoxCreator() {
}

Box BoxCreator::createBox(UtilBoxType type, int x, int y) {
    switch (type) {
    case UtilBoxType::kPace: {
        auto [w, h] = config_->paceSize();
        Box box(Point(x, y), w, h);
        box.setIndex(global_index_++);
        return box;
    }
    case UtilBoxType::kMall: {
        auto [w, h] = config_->mallSize();
        Box box(Point(x, y), w, h);
        box.setIndex(global_index_++);
        return box;
    } break;
    case UtilBoxType::kShop: {
        auto [w, h] = config_->shopSize();
        Box box(Point(x, y), w, h);
        box.setIndex(global_index_++);
        return box;
    } break;
    case UtilBoxType::kDefaltBuilding: {
        auto [w, h] = config_->defaltBuildingSize();
        Box box(Point(x, y), w, h);
        box.setIndex(global_index_++);
        return box;
    } break;

    default:
        break;
    }
}

Point BoxCreator::deduceBoxCenterPoint(UtilOrient orient, UtilBoxType box_type, Point anchor_point) {
    auto center_point     = anchor_point;
    auto [pace_w, pace_h] = config_->paceSize();
    switch (orient) {
    case UtilOrient::kToRight: {
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() - pace_w / 2 + w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
    } break;
    case UtilOrient::kToDown:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() + pace_w / 2 + w / 2);
            center_point.setX(center_point.rx() + config_->intervalSize());
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
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() + pace_w / 2 - w / 2);
            center_point.setY(center_point.ry() - pace_h / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToUp:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - config_->intervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);

        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - config_->intervalSize());
            center_point.setY(center_point.ry() + pace_h / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() - pace_w / 2 - w / 2);
            center_point.setX(center_point.rx() - config_->intervalSize());
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
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() + w);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() + w);
        } break;

        default:
            break;
        }
    } break;
    case UtilOrient::kToDown:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setY(center_point.ry() + h);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() + h);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToLeft:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() - w);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() - w);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToUp:
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setY(center_point.ry() - h);

        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setY(center_point.ry() - h);
        } break;
        case UtilBoxType::kNull: {
            auto [w, h] = config_->paceSize();
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

int BoxCreator::global_index_ = 0;
