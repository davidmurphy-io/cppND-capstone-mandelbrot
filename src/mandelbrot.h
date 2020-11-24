#include <io2d.h>

#include <thread>

using namespace std::experimental;

namespace mandelbrot_visualiser
{
    class Mandelbrot
    {
    public:
        Mandelbrot(io2d::output_surface &surface)
            : _width(surface.dimensions().x()), _height(surface.dimensions().y())
        {
        }

        void Display(io2d::output_surface &surface);

        void Step();

        void dump_array();

    private:
        void generate_mandelbrot(int thread_number);

        const int _width{};
        const int _height{};
        const int _maxInterations{1000};
        const double _middleX{-0.75}; // x offset
        const double _middleY{0};     // y offset
        const double _rangeX{3.5};
        const double _rangeY{2};

        const float _pxSize{1.f};

        // 2d vector - data grid
        //std::vector<std::vector<double>> _matrix{};
        double _matrix[400][400]{0};

        std::vector<std::thread> _threads{};
        const unsigned int _max_thread_count{std::thread::hardware_concurrency()};
    };
} // namespace mandelbrot_visualiser
