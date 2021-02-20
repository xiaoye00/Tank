#include "util.h"
#include <random>
#include <time.h>

static std::string install_path;

std::string InstallPath() {
    return install_path;
}

void setInstallPath(std::string path) {
    auto pos     = path.rfind("Tank");
    install_path = path.erase(pos);
}

unsigned int getRondomNumber(int x) {

    // static std::random_device rd;

    static std::default_random_engine random(time(NULL));

    std::uniform_int_distribution<int> dis(0, x);

    auto num = dis(random);

    return num;
}
