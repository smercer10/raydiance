#include "raydiance/colour.h"
#include "raydiance/interval.h"

void writeColour(std::ostream &out, colour pixelColour, int samplesPerPixel) {
    auto r = pixelColour.r();
    auto g = pixelColour.g();
    auto b = pixelColour.b();

    // Get average sample intensity for each colour channel
    auto scale = 1.0 / samplesPerPixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Colour intensity should remain within [0, 1] after scaling
    static const interval intensity(0.0, 0.999);

    // Convert to 8-bit colour representation and write to output stream
    out << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}