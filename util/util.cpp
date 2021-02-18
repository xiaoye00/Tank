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

unsigned int getRondomNumber() {

    std::default_random_engine random;

    auto num = random() % 6 + 1;

    return num;
}
