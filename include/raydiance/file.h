#pragma once
#include <fstream>
#include <string>

namespace file {
    std::string getTimestamp();
    std::ofstream openOutStream(const std::string &name);
}// namespace file