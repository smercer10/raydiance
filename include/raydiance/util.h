#pragma once
#include <fstream>
#include <string>

namespace util {
    std::string getTimestamp();
    std::ofstream openOutFile(const std::string &name);
}// namespace util