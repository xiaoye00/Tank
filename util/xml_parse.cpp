#include "xml_parse.h"

#include <QFile>

XmlParse::XmlParse() : QDomDocument() {
    
}

XmlParse::~XmlParse() {
}

bool XmlParse::initialFile(char* path) {
    QFile file(path);
    if (!file.open(QFile::ReadOnly)) return false;

    if (!setContent(&file)) {
        file.close();
        return false;
    }
    file.close();
    return true;
}
