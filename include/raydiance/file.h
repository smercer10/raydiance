#pragma once
#include <fstream>
#include <string>

namespace file {
    std::string getTimestamp();// Format: DD-MM-YYYY_HH-MM-SS
    std::ofstream openOutStream(const std::string &name);
}// namespace file