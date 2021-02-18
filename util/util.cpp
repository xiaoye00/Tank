#include "util.h"



static std::string install_path;

std::string InstallPath() 
{
   return install_path;
}

void setInstallPath(std::string path) 
{
    auto pos = path.rfind("Tank");
    install_path = path.erase(pos);
}
