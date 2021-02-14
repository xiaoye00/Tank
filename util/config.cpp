#include "config.h"

#include <QDebug>

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
                } else if (e.attribute("category") == "start pos") {
                    auto child_list = e.childNodes();
                    auto child_e    = child_list.at(0).toElement();
                    auto str        = child_e.text();
                    start_pos_x_    = str.toUInt();
                    child_e         = child_list.at(1).toElement();
                    str             = child_e.text();
                    start_pos_y_    = str.toUInt();
                }
            } else if (node.nodeName() == "placement") {
                //paces
                auto list_nodes = node.childNodes();
                for (auto i = 0; i < list_nodes.size(); i++) {
                    //pace
                    auto       node      = list_nodes.at(i);
                    auto       node_list = node.childNodes();
                    auto       e         = node_list.at(0).toElement();
                    auto       str       = e.text();
                    ConfigData data;
                    if (str == "tr") {
                        data.orient = UtilOrient::kToRight;
                    } else if (str == "td") {
                        data.orient = UtilOrient::kToDown;
                    } else if (str == "tl") {
                        data.orient = UtilOrient::kToLeft;
                    } else if (str == "tu") {
                        data.orient = UtilOrient::kToUp;
                    }
                    e        = node_list.at(1).toElement();
                    str      = e.text();
                    data.num = str.toUInt();
                    config_data_list_.push_back(data);
                }
            }
        }
    }
}
