/**
 * Madelbrot Visualuser - David Murphy (david@davidmurphy.io)
 **/

#include "mandelbrot.h"

#include <io2d.h>
#include <iostream>

using namespace std::experimental;

namespace mandelbrot_visualiser
{
    void run()
    {
        std::cout << "Mandelbrot Visualiser - mandelbrot_visualiser::run() called" << std::endl;

        auto display = io2d::output_surface{600, 400, io2d::format::argb32, io2d::scaling::none, io2d::refresh_style::fixed, 30.f};
        display.size_change_callback([&](io2d::output_surface &surface) {
            surface.dimensions(surface.display_dimensions());
        });

        auto mandelbrot{std::unique_ptr<Mandelbrot>()};

        display.draw_callback([&](io2d::output_surface &surface) {
            if (!mandelbrot)
            {
              mandelbrot = std::make_unique<Mandelbrot>(display);
            }
            mandelbrot->Step();
            mandelbrot->Display(surface);
        });
        display.begin_show();
    }
} // namespace mandelbrot_visualiser

int main()
{
    std::cout << "Mandelbrot Visualiser - Main() called" << std::endl;
    mandelbrot_visualiser::run();
}
