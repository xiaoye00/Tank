#include "config.h"


#include "xml_parse.h"
Config::Config() {
}

Config::~Config() {
}

bool Config::loadDesign(char* path) 
{
    auto xml = new XmlParse;
    xml->initialFile(path);
    return true;
}
