#pragma once

#include <QDomComment>

class XmlParse : public QDomDocument {
  public:
    XmlParse();
    ~XmlParse();

    bool initialFile(char* path);
};
