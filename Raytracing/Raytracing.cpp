// Raytracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STDC_LIB_EXT1

#include <iostream>
#include <fstream>
#include <vector>

#include "utility.h"
#include "hittable.h"
#include "hittable_list.h"
#include "camera.h"
#include "sphere.h"
//#include "stb_image_write.h"

using namespace std;

//double hit_sphere(const point3& center, double radius, const ray& r)
//{
//    vec3 oc = center - r.origin();
//    auto a = r.direction().length_squared();
//    auto h = dot(r.direction(), oc);
//    auto c = oc.length_squared() - radius * radius;
//    auto discriminant = h * h - a * c;
//
//    if (discriminant < 0) {
//        return -1.0;
//    }
//    else {
//        return (h - std::sqrt(discriminant)) / a;
//    }
//}

//color ray_color(const ray& r, const hittable& world)
//{
//    hit_record rec;
//    if (world.hit(r, interval(0, infinity), rec))
//    {
//        return 0.5 * (rec.normal + color(1, 1, 1));
//    }
//
//    vec3 unit_direction = unit_vector(r.direction());
//    auto a = 0.5 * (unit_direction.y() + 1.0);
//    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
//}

int main()
{
    //ofstream outfile;
    //outfile.open("imageInv.ppm");

    //auto aspect_ratio = 16.0 / 9.0;
    //int image_width = 1280;

    //// Calculate the image height, and ensure that it's at least 1.
    //int image_height = int(image_width / aspect_ratio);
    //image_height = (image_height < 1) ? 1 : image_height;

    hittable_list worldOfSpheres;

    worldOfSpheres.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    worldOfSpheres.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.samples_per_pixel = 10;

    cam.render(worldOfSpheres);

    //auto focal_length = 1.0;
    //auto viewport_height = 2.0;
    //auto viewport_width = viewport_height * (double(image_width) / image_height);
    //auto camera_center = point3(0, 0, 0);

    //auto viewport_u = vec3(viewport_width, 0, 0);
    //auto viewport_v = vec3(0, -viewport_height, 0);

    //auto pixel_delta_u = viewport_u / image_width;
    //auto pixel_delta_v = viewport_v / image_height;

    //auto viewport_upper_left = camera_center
    //    - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    //auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    ////std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    //outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    //std::vector<unsigned char> image_data(image_width * image_height * 3);
    //for (int idx = 0; idx < image_height; idx++)
    //{
    //    clog << "\rScanlines remaining: " << (image_height - idx) << ' ';
    //    for (int idx1 = 0; idx1 < image_width; idx1++)
    //    {
    //        /*auto r = double(idx1) / (image_width - 1);
    //        auto g = double(idx) / (image_height - 1);
    //        auto b = 0.0;

    //        int i_r = int(255.999 * r);
    //        int i_g = int(255.999 * g);
    //        int i_b = int(255.999 * b);

    //        outfile << i_r << ' ' << i_g << ' ' << i_b << '\n';*/
    //        

    //        auto pixel_center = pixel00_loc + (idx1 * pixel_delta_u) + (idx * pixel_delta_v);
    //        auto ray_direction = pixel_center - camera_center;
    //        ray ra(camera_center, ray_direction);

    //        color pixel_color = ray_color(ra, worldOfSpheres);
    //        vec3 colorV;
    //        write_color(std::cout, pixel_color, colorV);
    //        int index = (idx * image_width + idx1) * 3;
    //        image_data[index + 0] = colorV.x(); // R
    //        image_data[index + 1] = colorV.y(); // G
    //        image_data[index + 2] = colorV.z(); // B
    //    }
    //}
    //outfile.close();
    //  
    //std::clog << "\rDone.\n";
    //const char* filename = "image2.png";
    //stbi_write_png(filename, image_width, image_height, 3, image_data.data(), image_width * 3);
}