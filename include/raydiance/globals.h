#pragma once

inline constexpr auto aspectRatio = 16.0 / 9.0;
inline constexpr int imgWidth = 400;
inline constexpr int imgHeight = static_cast<int>(imgWidth / aspectRatio);
