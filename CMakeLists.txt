cmake_minimum_required(VERSION 3.11.3)

# Set the C++ standard we will use
set(CMAKE_CXX_STANDARD 17)

# Add the path of the cmake files to the CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

project(Mandelbrot_visualiser)

# Set library output path to /lib
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib")

# Locate project prerequisites
find_package(io2d REQUIRED)
find_package(Cairo)
find_package(GraphicsMagick)

# Set IO2D flags
set(IO2D_WITHOUT_SAMPLES 1)
set(IO2D_WITHOUT_TESTS 1)

# Add project executable
add_executable(Mandelbrot_visualiser src/main.cpp src/mandelbrot.cpp)

target_link_libraries(Mandelbrot_visualiser 
    PUBLIC io2d::io2d
)

# Set options for Linux or Microsoft Visual C++
if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    target_link_libraries(Mandelbrot_visualiser  PUBLIC pthread)
endif()

if(MSVC)
	target_compile_options(Mandelbrot_visualiser  PUBLIC /D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING /wd4459)
endif()
