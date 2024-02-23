#include "raydiance/util.h"
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

std::string util::getTimestamp() {
    const std::time_t now{std::time(nullptr)};

    std::tm tm{};

    // Not the end of the world if we can't get the timestamp
    if (localtime_s(&tm, &now)) {
        return "unknown";
    }

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y-%H-%M-%S");

    return oss.str();
}

std::ofstream util::openOutFile(const std::string &name) {
    if (!std::filesystem::exists(name)) {
        std::filesystem::create_directory(name);
    }

    const std::string filename{name + "-" + getTimestamp() + ".ppm"};

    // Put all images in the <name> subdirectory
    return std::ofstream{name + "/" + filename};
}