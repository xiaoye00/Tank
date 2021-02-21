#include "db.h"

namespace Tank {

DB::~DB() {
}

DB* DB::inst_ = nullptr;
} // namespace Tank