#include "raydiance/util.h"
#include <ctime>
#include <filesystem>
#include <iomanip>
#include <sstream>
#include <string>

std::string util::getTimestamp() {
    const time_t now{time(nullptr)};

    tm tm{};

    // Not critical if we can't get the time
    if (localtime_s(&tm, &now)) {
        return "";
    }

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");

    return oss.str();
}

std::ofstream util::openOutFile(const std::string &name) {
    if (!std::filesystem::exists(name)) {
        std::filesystem::create_directory(name);
    }

    const std::string filename{name + "-" + getTimestamp() + ".ppm"};

    return std::ofstream{name + "/" + filename};
}