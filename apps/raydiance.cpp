#include "raydiance/globals.h"
#include "raydiance/util.h"
#include <fstream>
#include <iostream>

int main() {
    std::ofstream imgOut{util::openOutFile("img")};

    if (!imgOut.is_open()) {
        std::cerr << "Failed to open output file.\n";
        return 1;
    }

    imgOut << "P3\n"
           << imgWidth << ' ' << imgHeight << "\n255\n";

    for (auto y{0}; y < imgHeight; ++y) {
        std::cout << "Scan lines remaining: " << imgHeight - y << '\n';

        for (auto x{0}; x < imgWidth; ++x) {
            auto r{static_cast<double>(x) / (imgWidth - 1)};
            const auto g{static_cast<double>(y) / (imgHeight - 1)};
            constexpr auto b{0};

            const auto ir{static_cast<int>(255.999 * r)};
            const auto ig{static_cast<int>(255.999 * g)};
            constexpr auto ib{static_cast<int>(255.999 * b)};

            imgOut << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::cout << "Done.\n";

    imgOut.close();

    return 0;
}