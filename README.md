# Mandelbrot Simulator

Mandelbrot simulator written in C++ using the io2d image library.

<img src="/images/mandelbrot_zoom.gif" width="600" height="400" title="Mandelbrot Simulator"/>

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
  ### Udacity Rubric points addressed
  #### Loops, Functions, I/O
  | Rubric point  | Location |
  | ------------- | ------------- |
  | A variety of control structures are used in the project. The project code is clearly organized into functions. | Evident through-out the project |

  #### Object Oriented Programming
  | Rubric point  | Location |
  | ------------- | ------------- |
  | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. | Evident through-out the project |
  | All class data members are explicitly specified as public, protected, or private. | [mandelbrot.h](./src/mandelbrot.h) |
  | All class members that are set to argument values are initialized through member initialization lists. | [mandelbrot.h](./src/mandelbrot.h) |
  | All class member functions document their effects, either through function names, comments, or formal documentation.  Member functions do not change program state in undocumented ways. | Evident through-out the project  |

  #### Memory Management
  | Rubric point  | Location |
  | ------------- | ------------- |
  | At least two variables are defined as references, or two functions use pass-by-reference in the project code. | Mandelbrot::Mandelbrot() and Mandelbrot::Display() [mandelbrot.h](./src/mandelbrot.h) |

  #### Concurrency
  | Rubric point  | Location |
  | ------------- | ------------- |
  | The project uses multiple threads in the execution. | Mandelbrot::Step() [mandelbrot.cpp](./src/mandelbrot.cpp) |
