# Mandelbrot Simulator

Mandelbrot simulator written in C++ using the io2d image library.

<img src="/images/mandelbrot.png" width="400" height="400" title="Mandelbrot Simulator"/>

## Cloning
Clone using either:
```
git clone https://github.com/davidmurphy-io/cppND-capstone-mandelbrot.git
```
or with SSH:
```
git clone git@github.com:davidmurphy-io/cppND-capstone-mandelbrot.git
```

## Dependencies for running locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it
  
  ## Compiling and Running
  
  ### Compiling
  To compile the project, first, create a `build` directory and change to that directory:
  ```
  mkdir build && cd build
  ```
  From within the `build` directory, then run `cmake` and `cmake --build` as follows:
  ```
  cmake ..
  cmake --build .
  ```
  ### Running
  The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
  ```
  ./Mandelbrot_visualiser
  ```
