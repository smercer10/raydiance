#include <fstream>
#include <string>

namespace util {
    static std::string getTimestamp();
    std::ofstream openOutFile(const std::string &name);
}// namespace util