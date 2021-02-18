#pragma once

#include <QDomDocument>

class XmlParse : public QDomDocument {
  public:
    XmlParse();
    ~XmlParse();

    bool initialFile(const char* path);
};
