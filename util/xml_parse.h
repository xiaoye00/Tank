#pragma once

#include <QDomDocument>

class XmlParse : public QDomDocument {
  public:
    XmlParse();
    ~XmlParse();

    bool initialFile(char* path);
};
