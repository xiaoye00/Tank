#include "util.h"
#include <random>

static std::string install_path;

std::string InstallPath() {
    return install_path;
}

void setInstallPath(std::string path) {
    auto pos     = path.rfind("Tank");
    install_path = path.erase(pos);
}

unsigned int getRondomNumber(int x) {

    std::default_random_engine random;

    auto num = random() % x;

    return num;
}
