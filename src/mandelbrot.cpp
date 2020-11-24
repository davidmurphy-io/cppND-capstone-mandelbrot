#include "mandelbrot.h"

#include <iostream>

namespace mandelbrot_visualiser
{
    void Mandelbrot::Display(io2d::output_surface &surface)
    {
        std::cout << "Mandelbrot::Display() called." << std::endl;

        //auto graph{io2d::path_builder{}};
        auto pb{io2d::path_builder{}};

        auto render_props{io2d::render_props{}};
        render_props.compositing(io2d::compositing_op::source);
        // /auto bp{io2d::brush_props{}};
        //auto x = float(surface.dimensions().x());
        //graph.new_figure({x, 0.f});
        //surface.paint(io2d::brush{io2d::rgba_color::white});

        for (auto x = 0; x < 400; ++x)
        {
            for (auto y = 0; y < 400; ++y)
            {
                render_props.surface_matrix(io2d::matrix_2d::create_translate({_pxSize * x, _pxSize * y}));
                pb.new_figure({0.f, 0.f});
                pb.line({1.f, 0.f});
                pb.line({0.f, 1.f});
                pb.line({-1.f, 0.f});
                pb.line({0.f, -1.f});
                //graph.line({x, _matrix[y]});
                //std::cout << "R: " << _matrix[x][y] * 255 / 2 << " B: " << _matrix[x][y] * 255 / 0.1 << " G: " << _matrix[x][y] * 255 / 2.5 << std::endl;
                auto brush{io2d::brush{io2d::rgba_color{(int)(_matrix[x][y] * 255), (int)(_matrix[x][y] * 255 ), (int)(_matrix[x][y] * 255), 255}}};
                surface.fill(brush, io2d::interpreted_path{pb}, std::nullopt, render_props);
                //
                //surface.fill(io2d::brush{io2d::rgba_color{(int)(_matrix[x][y] * 255), (int)(_matrix[x][y] * 255 ), (int)(_matrix[x][y] * 255), 255}}, io2d::interpreted_path{pb}, std::nullopt, render_props);
                //surface.stroke(brush, pb);
                pb.clear();
            }
        }
        //graph.close_figure();
        //
        //surface.fill(io2d::brush{io2d::rgba_color::white}, graph);
        std::cout << "End of Display()" << std::endl << std::endl;
    }

    void Mandelbrot::Step()
    {
        std::cout << "Step called" << std::endl;
        for(int i = 1; i < _max_thread_count; ++i)
        {
            std::cout << "1st loop, thread size: " << _threads.size() << std::endl;
            _threads.emplace( _threads.end(), std::thread([i, this](){this->generate_mandelbrot(i);}));
            std::cout << "after emplace" << std::endl;
        }

        for(int thread = 0; thread <= _threads.size()-1; ++thread)
        {
            _threads[thread].join();
        }

        _threads.erase(_threads.begin(), _threads.end());
        //generate_mandelbrot();
        //dump_array();
    }

    void Mandelbrot::generate_mandelbrot(int thread_number)
    {
        std::cout << "Mandelbrot::generate_mandelbrot() called. Thread Num: " << thread_number << std::endl;
        for (int x = 0; x < _width; x+= thread_number)
        {
            for (int y = 0; y < _height; y++)
            {
                double xScale = (double)x / (double)_width;
                double yScale = (double)y / (double)_height;

                double cReal = xScale * _rangeX + _middleX - _rangeX / 2;
                double cImaginary = yScale * _rangeY + _middleY - _rangeY / 2;

                double zReal = 0;
                double zImaginary = 0;

                int iteration = 0;

                while (iteration < _maxInterations && zReal * zReal + zImaginary * zImaginary <= 4)
                {
                    double oldZ = zReal;
                    zReal = zReal * zReal - zImaginary * zImaginary + cReal;
                    zImaginary = 2 * oldZ * zImaginary + cImaginary;
                    iteration++;
                }

                _matrix[x][y] = (double)iteration / (double)_maxInterations;
                //std::cout << _matrix[x][y] << std::endl;
            }
        }
        std::cout << "Generate finished on thread: " << thread_number << std::endl;
    }

    void Mandelbrot::dump_array()
    {
        for (int x = 0; x <= _width; x++)
        {
            for (int y = 0; y <= _height; y++)
            {
                std::cout << _matrix[x][y] << ", ";
            }
            std::cout  << std::endl;
        }
    }

} // namespace mandelbrot_visualiser
