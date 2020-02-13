# Elevator Simulator

This project is a console application that simulates a single elevator system.

## Project Overview
1. The user enters the number of floors in the building.
2. To simulate pre-existing elevator requests, the user enters a random number `x` and the system automatically generates `x` 
   number of random pre-exising elevator requests.
3. Then, the user enters their actual request by entering the current floor and the direction they need to go(up/down).
4. Then, the system takes in account all pre-existing requests as well as the current user request to simulate the behaviour
   of the elevator.

## File Structure
`
Elevator_Simulator
|
+-- include
|   |
|   +-- Controller.h
|   |
|   +-- Elevator.h
|
+-- src
|   |
|   +-- Controller.cpp
|   |
|   +-- Elevator.cpp
|   |
|   +-- Simulator.cpp
|
+-- CMakeLists.txt
|
+-- README.md
`

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./HelloWorld`.

## Rubric points addressed

### Loops, Functions, I/O

| Criteria | File/Line |
| --- | --- |
| The project demonstrates an understanding of C++ functions and control structures. | Elevator.cpp, Controller.cpp |
| The project accepts user input and processes the input. | Simulator.cpp |

### Object Oriented Programming

| Criteria | File/Line |
| --- | --- |
| The project uses Object Oriented Programming techniques.| Elevator.h, Controller.h |
| Classes use appropriate access specifiers for class members. | Elevator.h, Controller.h |
| Class constructors utilize member initialization lists.| Elevator.h (line 14), Controller.h (line 17) |
| Classes abstract implementation details from their interfaces.| Elevator.h, Controller.h |
| Classes encapsulate behavior. | Elevator.h, Controller.h |