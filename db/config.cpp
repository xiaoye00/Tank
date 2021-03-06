#include "config.h"

#include <QDebug>

#include "db_def.h"
#include "player.h"
#include "transform.h"
#include "xml_parse.h"

namespace tank {
Config::Config() {
}

Config::~Config() {
}

bool Config::loadDesign(const char* path) {
    XmlParse xml;
    if (!xml.initialFile(path)) {
        return false;
    }

    auto db = DB::getInstance();

    //to root
    QDomElement root = xml.documentElement();
    qDebug() << root.nodeName();
    if (root.hasChildNodes()) {
        auto list_nodes = root.childNodes();
        for (auto i = 0; i < list_nodes.size(); i++) {
            auto node = list_nodes.at(i);
            if (node.nodeName() == "item") {
                auto e = node.toElement();
                if (e.attribute("category") == "map size") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    auto map_size_w = str.toUInt();
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    auto map_size_h = str.toUInt();
                    db->setMapSize(map_size_w, map_size_h);
                } else if (e.attribute("category") == "pace size") {
                    auto child_list  = e.childNodes();
                    auto child_e     = child_list.at(0).toElement();
                    auto str         = child_e.text();
                    auto pace_size_w = str.toUInt();
                    child_e          = child_list.at(1).toElement();
                    str              = child_e.text();
                    auto pace_size_h = str.toUInt();
                    db->setPaceSize(pace_size_w, pace_size_h);
                } else if (e.attribute("category") == "interval size") {
                    auto child_list    = e.childNodes();
                    auto child_e       = child_list.at(0).toElement();
                    auto str           = child_e.text();
                    auto interval_size = str.toUInt();
                    child_e            = child_list.at(1).toElement();
                    str                = child_e.text();
                    // interval_size_  = str.toUInt();
                    db->setIntervalSize(interval_size);
                } else if (e.attribute("category") == "mall size") {
                    auto [pace_size_w, pace_size_h] = db->PaceSize();
                    auto child_list                 = e.childNodes();
                    auto child_e                    = child_list.at(0).toElement();
                    auto str                        = child_e.text();
                    auto mall_size_w                = str.toUInt() * pace_size_w;
                    child_e                         = child_list.at(1).toElement();
                    str                             = child_e.text();
                    auto mall_size_h                = str.toUInt() * pace_size_h;
                    db->setMallSize(mall_size_w, mall_size_h);
                } else if (e.attribute("category") == "shop size") {
                    auto [pace_size_w, pace_size_h] = db->PaceSize();
                    auto child_list                 = e.childNodes();
                    auto child_e                    = child_list.at(0).toElement();
                    auto str                        = child_e.text();
                    auto shop_size_w                = str.toUInt() * pace_size_w;
                    child_e                         = child_list.at(1).toElement();
                    str                             = child_e.text();
                    auto shop_size_h                = str.toUInt() * pace_size_h;
                    db->setShopSize(shop_size_w, shop_size_h);
                } else if (e.attribute("category") == "defalt size") {
                    auto [pace_size_w, pace_size_h] = db->PaceSize();
                    auto child_list                 = e.childNodes();
                    auto child_e                    = child_list.at(0).toElement();
                    auto str                        = child_e.text();
                    auto defalt_building_size_w     = str.toUInt() * pace_size_w;
                    child_e                         = child_list.at(1).toElement();
                    str                             = child_e.text();
                    auto defalt_building_size_h     = str.toUInt() * pace_size_h;
                    db->setDefaltBuildingSize(defalt_building_size_w, defalt_building_size_h);
                } else if (e.attribute("category") == "start pos") {
                    auto child_list     = e.childNodes();
                    auto child_e        = child_list.at(0).toElement();
                    auto str            = child_e.text();
                    auto origin_point_x = str.toUInt();
                    child_e             = child_list.at(1).toElement();
                    str                 = child_e.text();
                    auto origin_point_y = str.toUInt();
                    db->setOriginPoint(origin_point_x, origin_point_y);
                } else if (e.attribute("category") == "building level") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    auto value      = str.toUInt();
                    Building::setMaxBuildingLevel(value);

                } else if (e.attribute("category") == "mall toll") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    auto value      = str.toUInt();
                    Building::setMallTollBase(value);

                } else if (e.attribute("category") == "null toll") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    auto value      = str.toUInt();
                    Building::setNullTollBase(value);

                } else if (e.attribute("category") == "defalt toll") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    auto value      = str.toUInt();
                    Building::setDefaltTollBase(value);

                } else if (e.attribute("category") == "shop toll") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    auto value      = str.toUInt();
                    Building::setShopTollBase(value);
                }
            } else if (node.nodeName() == "placement") {
                BoxCreator creator;
                creator.setConfig(this);
                auto [map_size_w, map_size_h] = db->MapSize();
                Transform transform_map(map_size_w, map_size_h);
                auto [origin_point_x, origin_point_y] = db->OriginPoint();
                auto anchor_point                     = Point(origin_point_x, origin_point_y);
                //paces
                auto list_nodes = node.childNodes();
                for (auto i = 0; i < list_nodes.size(); i++) {
                    //pace
                    auto node      = list_nodes.at(i);
                    auto node_list = node.childNodes();

                    auto e   = node_list.at(1).toElement();
                    auto str = e.text();
                    auto num = str.toUInt();

                    e   = node_list.at(0).toElement();
                    str = e.text();
                    PlacementOrient orient;
                    if (str == "tr") {
                        orient = PlacementOrient::kToRight;
                    } else if (str == "td") {
                        orient = PlacementOrient::kToDown;
                    } else if (str == "tl") {
                        orient = PlacementOrient::kToLeft;
                    } else if (str == "tu") {
                        orient = PlacementOrient::kToUp;
                    }
                    Box*  pace_box;
                    Point last_center_point;
                    for (int i = 0; i < num; i++) {
                        if (i == 0) {
                            pace_box          = creator.createBox(BoxType::kPace, anchor_point.rx(), anchor_point.ry());
                            last_center_point = pace_box->getCenterPoint();
                            auto box          = transform_map.translateToSceneBox(pace_box);
                            auto pace         = new Pace;
                            pace->setBox(box);
                            db->appendPaceBox(pace);
                        } else {
                            auto point        = creator.deduceBoxCenterPoint(orient, BoxType::kPace, last_center_point);
                            pace_box          = creator.createBox(BoxType::kPace, point.rx(), point.ry());
                            last_center_point = pace_box->getCenterPoint();
                            auto box          = transform_map.translateToSceneBox(pace_box);
                            auto pace         = new Pace;
                            pace->setBox(box);
                            db->appendPaceBox(pace);
                        }
                    }

                    //building
                    e                    = node_list.at(2).toElement();
                    auto building_nodes  = e.childNodes();
                    auto building_anchor = anchor_point;
                    for (int i = 0; i < building_nodes.size(); i++) {
                        auto building = building_nodes.at(i).toElement().text();
                        if (building == "defalt") {
                            auto point = creator.deduceBoxCenterPoint(orient, BoxType::kDefaltBuilding, building_anchor);
                            auto box   = creator.createBox(BoxType::kDefaltBuilding, point.rx(), point.ry());
                            box        = transform_map.translateToSceneBox(box);

                            auto building = new Building;
                            building->setBox(box);
                            db->appendBuildingBox(building);
                            creator.associateBuildingBox(orient, building);

                            building_anchor = creator.deduceNextAnchorPoint(orient, BoxType::kDefaltBuilding, building_anchor);

                        } else if (building == "mall") {
                            auto point = creator.deduceBoxCenterPoint(orient, BoxType::kMall, building_anchor);
                            auto box   = creator.createBox(BoxType::kMall, point.rx(), point.ry());

                            box = transform_map.translateToSceneBox(box);

                            auto building = new Building;
                            building->setBox(box);
                            db->appendBuildingBox(building);
                            creator.associateBuildingBox(orient, building);

                            building_anchor = creator.deduceNextAnchorPoint(orient, BoxType::kMall, building_anchor);

                        } else if (building == "shop") {
                            auto point = creator.deduceBoxCenterPoint(orient, BoxType::kShop, building_anchor);
                            auto box   = creator.createBox(BoxType::kShop, point.rx(), point.ry());

                            box = transform_map.translateToSceneBox(box);

                            auto building = new Building;
                            building->setBox(box);
                            db->appendBuildingBox(building);
                            creator.associateBuildingBox(orient, building);

                            building_anchor = creator.deduceNextAnchorPoint(orient, BoxType::kShop, building_anchor);
                        } else if (building == "null") {
                            auto point      = creator.deduceBoxCenterPoint(orient, BoxType::kNull, building_anchor);
                            building_anchor = creator.deduceNextAnchorPoint(orient, BoxType::kNull, building_anchor);
                        }
                    }

                    auto [pace_size_w, pace_size_h] = db->PaceSize();

                    if (str == "tr") {
                        anchor_point.setX(anchor_point.rx() + pace_size_w * (num));
                    } else if (str == "td") {
                        anchor_point.setY(anchor_point.ry() + pace_size_h * (num));
                    } else if (str == "tl") {
                        anchor_point.setX(anchor_point.rx() - pace_size_w * (num));
                    } else if (str == "tu") {
                        anchor_point.setX(anchor_point.ry() - pace_size_h * (num));
                    }
                }
            } else if (node.nodeName() == "players") {
                auto list_nodes = node.childNodes();
                for (auto i = 0; i < list_nodes.size(); i++) {
                    auto node = list_nodes.at(i);
                    if (node.nodeName() == "player") {

                        auto          attr_name = node.toElement().attribute("name");
                        auto          name      = attr_name.toLocal8Bit();
                        auto          c_name    = name.constData();
                        auto          node_list = node.childNodes();
                        auto          e         = node_list.at(0).toElement();
                        auto          str       = e.text();
                        auto          pos       = str.toInt();
                        PlayerCreator creator;
                        auto          player = creator.createPlayer(c_name);
                        player->setID(i);

                        e          = node_list.at(1).toElement();
                        str        = e.text();
                        auto local = str.toLocal8Bit();
                        auto color = local.data();
                        player->setColor(color);

                        e          = node_list.at(2).toElement();
                        str        = e.text();
                        auto money = str.toInt();
                        player->setMoney(money);

                        db->appendPlayer(player);
                    }
                    // auto c_node_name =
                }
            }
        }
    }
}
} // namespace tank
