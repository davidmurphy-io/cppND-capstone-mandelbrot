#include <io2d.h>
#include <complex>
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

        int calculate_point(std::complex<double> c);

        const int _width{};
        const int _height{};
        const int _maxIterations{80};
        double _middleX{-0.75}; // x offset
        double _middleY{0};     // y offset
        double _rangeX{3.5};
        double _rangeY{2};

        const float _pxSize{1.f};

        // 2d array[hue data][value data]
        float _matrix[600][400][2]{0.0f};

        std::vector<std::thread> _threads{};
        const unsigned int _max_thread_count{std::thread::hardware_concurrency()};

        const float _saturation{1.0f};
        static const int _hue_pos{0};
        static const int _value_pos{1};
    };
} // namespace mandelbrot_visualiser
