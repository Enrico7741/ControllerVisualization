//--------------------------------------------------------------------------------------------------
// Cross-Platform Controller Input Visualization
// Copyright (C) 2021 Enrico Schörnick
// Licensed under the MIT License
//--------------------------------------------------------------------------------------------------

#ifndef VISUALIZATION_LAYOUT_HPP
#define VISUALIZATION_LAYOUT_HPP

#include <vector>
#include <utility>
#include <cstdint>

/**
 * Namespace for global constants concerning the layout.
 * Constants defined here shall be used throughout all layout relevant code.
 */
namespace Layout
{
    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    namespace Colors
    {
        const Color text{0, 0, 0};
        const Color background{25, 35, 45};
    }

    namespace Box
    {
        const int margin{11};
        const int padding{5};
        const int outlineThickness{4};
    }
}

#endif