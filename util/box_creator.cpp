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

Point BoxCreator::calcuNextBoxCenter(UtilOrient orient, UtilBoxType box_type, Box box) {
    auto center_point = box.getCenterPoint();
    switch (orient) {
    case UtilOrient::kToRight: {
        center_point.setX(center_point.rx() + box.Width() / 2);
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() + w / 2);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() + w / 2);
            center_point.setY(center_point.ry() - box.Height() / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() + w / 2);
            center_point.setY(center_point.ry() - box.Height() / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() + w / 2);
            center_point.setY(center_point.ry() - box.Height() / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
    } break;
    case UtilOrient::kToDown:
        center_point.setY(center_point.ry() + box.Height() / 2);
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() + w / 2);
            center_point.setX(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.ry() + box.Height() / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() + w / 2);
            center_point.setX(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.ry() + box.Height() / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() + w / 2);
            center_point.setX(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.ry() + box.Height() / 2);
            center_point.setY(center_point.ry() + h / 2);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToLeft:
        center_point.setX(center_point.rx() - box.Width() / 2);
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setX(center_point.rx() - w / 2);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setX(center_point.rx() - w / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - box.Height() / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setX(center_point.rx() - w / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - box.Height() / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setX(center_point.rx() - w / 2);
            center_point.setY(center_point.ry() - config_->intervalSize());
            center_point.setY(center_point.ry() - box.Height() / 2);
            center_point.setY(center_point.ry() - h / 2);
        } break;

        default:
            break;
        }
        break;
    case UtilOrient::kToUp:
        center_point.setY(center_point.ry() - box.Height() / 2);
        switch (box_type) {
        case UtilBoxType::kPace: {
            auto [w, h] = config_->paceSize();
            center_point.setY(center_point.ry() - h / 2);
        } break;
        case UtilBoxType::kMall: {
            auto [w, h] = config_->mallSize();
            center_point.setY(center_point.ry() - h / 2);
            center_point.setX(center_point.rx() + box.Width() / 2);
            center_point.setY(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.rx() + w / 2);

        } break;
        case UtilBoxType::kShop: {
            auto [w, h] = config_->shopSize();
            center_point.setY(center_point.ry() - h / 2);
            center_point.setX(center_point.rx() + box.Width() / 2);
            center_point.setY(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.rx() + w / 2);
        } break;
        case UtilBoxType::kDefaltBuilding: {
            auto [w, h] = config_->defaltBuildingSize();
            center_point.setY(center_point.ry() - h / 2);
            center_point.setX(center_point.rx() + box.Width() / 2);
            center_point.setY(center_point.rx() + config_->intervalSize());
            center_point.setY(center_point.rx() + w / 2);
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



int BoxCreator::global_index_ = 0;
