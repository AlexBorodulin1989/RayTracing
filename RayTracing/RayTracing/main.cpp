//
//  main.cpp
//  RayTracing
//
//  Created by Aleksandr Borodulin on 27.09.2023.
//
#include "color.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // Image

    int image_width = 256;
    int image_height = 256;

    //Render

    std::ofstream output;
    output.open("image.ppm");

    output << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::cout << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            auto pixel_color = color(r, g, b);
            write_color(output, pixel_color);
        }
    }

    output.close();

    std::cout << "\rDone.           \n";
    return 0;
}
