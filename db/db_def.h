#pragma once

namespace Tank {

enum class BoxType {
    kPace,
    kMall,
    kShop,
    kDefaltBuilding,
    kNull
};

enum class PlacementOrient {
    kToRight,
    kToDown,
    kToLeft,
    kToUp
};

enum class GoOrient{
    kGoAhead,
    kGoBack
};

} // namespace Tank
