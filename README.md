# CppND-Capstone-Pong-Game

This is my version of the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

<img src="PongGame.gif"/>

The Pong Game provided inside this repository represents a two player game, where each of the two boards is getting controlled via the keyboard.
The left board gets controlled via the keys W (Up) and S (Down) whereas the right board gets controlled via the arrow keys Up and Down.
During the game, the ball will increase its speed so that it gets harder the longer both of the player survive.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.

## Rubric points addressed
### Loops, Functions, I/O
| Rubric point  | Location |
| ------------- | ------------- |
| The project demonstrates an understanding of C++ functions and control structures.  |   Yes, check all the files
| The project accepts user input and processes the input. | [Controller](src/controller.cpp)

### Object Oriented Programming
| Rubric point  | Location |
| ------------- | ------------- |
| The project uses Object Oriented Programming techniques.  |   Yes, check all the files
| Classes use appropriate access specifiers for class members. | Yes, check all the files
| Class constructors utilize member initialization lists. | Yes, check all the files
| Classes abstract implementation details from their interfaces. | Yes, check all the files
| Classes encapsulate behavior. | Yes, check all the files

### Memory Management
| Rubric point  | Location |
| ------------- | ------------- |
| The project makes use of references in function declarations.  |   Yes, check all the files)
| The project uses destructors appropriately. | [Board](src/board.h))
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | Yes, check all the files
| The project follows the Rule of 5. | Yes, check all the files
| The project uses move semantics to move data, instead of copying it, where possible. | Yes, check all the files
| The project uses smart pointers instead of raw pointers. | Yes, check [Game](src/game.cpp)


## MIT
### The MIT License
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)  
`[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)`
