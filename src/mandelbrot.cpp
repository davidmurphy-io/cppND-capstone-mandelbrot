#include "mandelbrot.h"

#include <cmath>
#include <complex>
#include <iostream>

namespace mandelbrot_visualiser
{
    void Mandelbrot::Display(io2d::output_surface &surface)
    {
        std::cout << "Mandelbrot::Display() called." << std::endl;

        auto pb{io2d::path_builder{}};
        auto render_props{io2d::render_props{}};
        render_props.compositing(io2d::compositing_op::source);
        surface.paint(io2d::brush{io2d::rgba_color::white});

        for (auto x = 0; x < _width;  ++x)
        {
            for (auto y = 0; y < _height; ++y)
            {
                render_props.surface_matrix(io2d::matrix_2d::create_translate({_pxSize * x, _pxSize * y}));
                pb.new_figure({0.f, 0.f});
                pb.line({1.f, 0.f});
                pb.line({0.f, 1.f});
                pb.line({-1.f, 0.f});
                pb.line({0.f, -1.f});

                auto hue{_matrix[x][y][_hue_pos]};
                auto value{_matrix[x][y][_value_pos]};
                auto brush{io2d::brush{io2d::rgba_from_HSV(hue, _saturation, value)}};
                surface.fill(brush, io2d::interpreted_path{pb}, std::nullopt, render_props);
                pb.clear();
            }
        }
        std::cout << "End of Display()" << std::endl << std::endl;
    }

    void Mandelbrot::Step()
    {
        std::cout << "Step called" << std::endl;

        // Spawn multiple threads for calculation.
        for(int i = 1; i < _max_thread_count; ++i)
        {
            // async / package tasks ??
            std::cout << "1st loop, thread size: " << _threads.size() << std::endl;
            _threads.emplace_back( std::thread([i, this](){this->generate_mandelbrot(i);}));
            std::cout << "after emplace" << std::endl;
        }

        // Thread tidy up.
        std::cout << "thread tidy up" << std::endl;
        for(int thread = 0; thread < _threads.size(); ++thread)
        {
            std::cout << "_thread[" << thread << "] of " << _threads.size() << std::endl;
            if (_threads[thread].joinable())
            {
                _threads[thread].join();
            }
        }
        _threads.erase(_threads.begin(), _threads.end());

        // Step variables for next iteration
        // Zoom in
        _rangeX *= 0.8;
        _rangeY *= 0.8;
        // Pan left & up
        _middleX -= 0.0075;
        _middleY -= 0.012;
    }

    void Mandelbrot::generate_mandelbrot(int thread_number)
    {
        std::cout << "Mandelbrot::generate_mandelbrot() called. Thread Num: " << thread_number << std::endl;

        std::cout << std::fixed << std::setprecision(10);

        for (int x = thread_number-1; x < _width;  x += (int)_max_thread_count-1)
        {
            for (int y = 0; y < _height; y++)
            {
                double scale_x{(double)x/(double)_width};
                double scale_y{(double)y/(double)_height};

                std::complex<double> c{scale_x * _rangeX + _middleX - _rangeX / 2,
                                       scale_y * _rangeY + _middleY - _rangeY / 2};

                std::complex<double> z{0};
                int iterations{0};

                while (std::abs(z) <= 2 && iterations < _maxIterations)
                {
                    z = z * z + c;
                    iterations++;
                }

                _matrix[x][y][_hue_pos] = (float)(360.0f * iterations / _maxIterations);
                _matrix[x][y][_value_pos] = (iterations < _maxIterations) ? 1.0f : 0.0f;

            }
        }
        std::cout << "Generate finished on thread: " << thread_number << std::endl;
    }

    // Currently unused - useful for debug outside of io2d
    void Mandelbrot::dump_array()
    {
        for (int x = 0; x <= _width; x++)
        {
            for (int y = 0; y <= _height; y++)
            {
                std::cout << _matrix[x][y][_hue_pos] << ", ";
            }
            std::cout  << std::endl;
        }
    }

} // namespace mandelbrot_visualiser
