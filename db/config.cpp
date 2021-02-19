#include "config.h"

#include <QDebug>

#include "db_def.h"
#include "transform.h"
#include "xml_parse.h"

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
                    UtilOrient orient;
                    if (str == "tr") {
                        orient = UtilOrient::kToRight;
                    } else if (str == "td") {
                        orient = UtilOrient::kToDown;
                    } else if (str == "tl") {
                        orient = UtilOrient::kToLeft;
                    } else if (str == "tu") {
                        orient = UtilOrient::kToUp;
                    }
                    Box pace_box;
                    for (int i = 0; i < num; i++) {
                        if (i == 0) {
                            pace_box = creator.createBox(UtilBoxType::kPace, anchor_point.rx(), anchor_point.ry());
                            auto box = transform_map.translateToSceneBox(pace_box);
                            db->appendPaceBox(box);
                        } else {
                            auto point = creator.deduceBoxCenterPoint(orient, UtilBoxType::kPace, pace_box.getCenterPoint());
                            pace_box   = creator.createBox(UtilBoxType::kPace, point.rx(), point.ry());
                            auto box   = transform_map.translateToSceneBox(pace_box);
                            db->appendPaceBox(box);
                        }
                    }

                    //building
                    e                    = node_list.at(2).toElement();
                    auto building_nodes  = e.childNodes();
                    auto building_anchor = anchor_point;
                    for (int i = 0; i < building_nodes.size(); i++) {
                        auto building = building_nodes.at(i).toElement().text();
                        if (building == "defalt") {
                            auto point = creator.deduceBoxCenterPoint(orient, UtilBoxType::kDefaltBuilding, building_anchor);
                            auto box   = creator.createBox(UtilBoxType::kDefaltBuilding, point.rx(), point.ry());

                            box = transform_map.translateToSceneBox(box);
                            creator.associateBuildingBox(orient, box);
                            db->appendBuildingBox(box);
                            building_anchor = creator.deduceNextAnchorPoint(orient, UtilBoxType::kDefaltBuilding, building_anchor);

                        } else if (building == "mall") {
                            auto point = creator.deduceBoxCenterPoint(orient, UtilBoxType::kMall, building_anchor);
                            auto box   = creator.createBox(UtilBoxType::kMall, point.rx(), point.ry());

                            box = transform_map.translateToSceneBox(box);
                            creator.associateBuildingBox(orient, box);
                            db->appendBuildingBox(box);
                            building_anchor = creator.deduceNextAnchorPoint(orient, UtilBoxType::kMall, building_anchor);

                        } else if (building == "shop") {
                            auto point = creator.deduceBoxCenterPoint(orient, UtilBoxType::kShop, building_anchor);
                            auto box   = creator.createBox(UtilBoxType::kShop, point.rx(), point.ry());

                            box = transform_map.translateToSceneBox(box);
                            creator.associateBuildingBox(orient, box);
                            db->appendBuildingBox(box);
                            building_anchor = creator.deduceNextAnchorPoint(orient, UtilBoxType::kShop, building_anchor);
                        } else if (building == "null") {
                            auto point      = creator.deduceBoxCenterPoint(orient, UtilBoxType::kNull, building_anchor);
                            building_anchor = creator.deduceNextAnchorPoint(orient, UtilBoxType::kNull, building_anchor);
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
            }
        }
    }
}
