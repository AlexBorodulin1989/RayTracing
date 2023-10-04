//
//  main.cpp
//  RayTracing
//
//  Created by Aleksandr Borodulin on 27.09.2023.
//

#include <iostream>
#include <fstream>

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

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            output << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    output.close();

    std::cout << "\rDone.           \n";
    return 0;
}
