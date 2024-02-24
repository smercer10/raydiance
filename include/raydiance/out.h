#pragma once
#include <fstream>
#include <string>

namespace out {
    inline constexpr auto aspectRatio = 16.0 / 9.0;
    inline constexpr int imgWidth = 400;
    inline constexpr int imgHeight = static_cast<int>(imgWidth / aspectRatio);

    std::string getTimestamp();
    std::ofstream openOutFile(const std::string &name);
}// namespace out