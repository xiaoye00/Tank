#include "box_creator.h"

BoxCreator::BoxCreator(/* args */) {
}

BoxCreator::~BoxCreator() {
}

Box BoxCreator::createBox(UtilBoxType type, int x, int y) {
    switch (type) {
    case UtilBoxType::kPace: {
        auto [pace_w, pace_h] = config_->paceSize();
        return Box(Point(x,y), pace_w, pace_h);
    }

    break;

    default:
        break;
    }
}
