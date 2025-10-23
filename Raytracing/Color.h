#pragma once

#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

#include <iostream> 
#include <fstream>
#include "utility.h"

using color = vec3;
using namespace std;

void write_color(std::ostream& out, const color& pixel_color, vec3 &ColorV)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.0, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    ColorV = *new vec3(rbyte, gbyte, bbyte);

    // Write out the pixel color components.
    //out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif