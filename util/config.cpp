#include "config.h"

#include <QDebug>

#include "transform.h"
#include "util_def.h"
#include "xml_parse.h"

Config::Config() {
}

Config::~Config() {
}

bool Config::loadDesign(char* path) {
    XmlParse xml;
    if (!xml.initialFile(path)) {
        return false;
    }

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
                    map_size_w_     = str.toUInt();
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    map_size_h_     = str.toUInt();
                } else if (e.attribute("category") == "pace size") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    pace_size_w_    = str.toUInt();
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    pace_size_h_    = str.toUInt();
                } else if (e.attribute("category") == "interval size") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    interval_size_  = str.toUInt();
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    interval_size_  = str.toUInt();
                } else if (e.attribute("category") == "mall size") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    mall_size_w_    = str.toUInt() * pace_size_w_;
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    mall_size_h_    = str.toUInt() * pace_size_h_;
                } else if (e.attribute("category") == "shop size") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    shop_size_w_    = str.toUInt() * pace_size_w_;
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    shop_size_h_    = str.toUInt() * pace_size_h_;
                } else if (e.attribute("category") == "defalt size") {
                    auto child_list         = e.childNodes();
                    auto child_e            = child_list.at(0).toElement();
                    auto str                = child_e.text();
                    defalt_building_size_w_ = str.toUInt() * pace_size_w_;
                    child_e                 = child_list.at(1).toElement();
                    str                     = child_e.text();
                    defalt_building_size_h_ = str.toUInt() * pace_size_h_;
                } else if (e.attribute("category") == "start pos") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    origin_point_x_ = str.toUInt();
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    origin_point_y_ = str.toUInt();
                }
            } else if (node.nodeName() == "placement") {
                BoxCreator creator;
                creator.setConfig(this);
                
                Transform transform_map(map_size_w_, map_size_h_);
                Box       pace_box = creator.createBox(UtilBoxType::kPace, origin_point_x_, origin_point_y_);
                auto      box = transform_map.translateToSceneBox(pace_box);
                pace_box_list_.push_back(box);
                auto anchor_point = Point(origin_point_x_, origin_point_y_);
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

                    for (int i = 0; i < num; i++) {
                        auto point = creator.calcuNextBoxCenter(orient, UtilBoxType::kPace, pace_box);
                        pace_box   = creator.createBox(UtilBoxType::kPace, point.rx(), point.ry());
                        auto box   = transform_map.translateToSceneBox(pace_box);
                        pace_box_list_.push_back(box);
                    }

                    //building
                    e                   = node_list.at(2).toElement();
                    auto building_nodes = e.childNodes();
                    for (int i = 0; i < building_nodes.size(); i++) {
                        auto building = building_nodes.at(i).toElement().text();
                        if (building == "defalt") {

                        } else if (building == "mall") {

                        } else if (building == "shop") {
                        }
                    }

                    if (str == "tr") {
                        anchor_point.setX(anchor_point.rx() + pace_size_w_ * (num));
                    } else if (str == "td") {
                        anchor_point.setY(anchor_point.ry() + pace_size_h_ * (num));
                    } else if (str == "tl") {
                        anchor_point.setX(anchor_point.rx() - pace_size_w_ * (num));
                    } else if (str == "tu") {
                        anchor_point.setX(anchor_point.ry() - pace_size_h_ * (num));
                    }
                }
            }
        }
    }
}
