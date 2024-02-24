#include "raydiance/colour.h"
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
            colour pixelColour{static_cast<double>(x) / (imgWidth - 1),
                               static_cast<double>(y) / (imgHeight - 1),
                               0};

            pixelColour.write(imgOut);
        }
    }

    std::cout << "Done.\n";

    imgOut.close();

    return 0;
}