# Modular C++ library with CMake [![Build Status](https://travis-ci.org/martijnkoopman/Modular-Cpp-library.svg?branch=master)](https://travis-ci.org/martijnkoopman/Modular-Cpp-library) [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## Introduction
This repository is a template for a modular C++ library.

### Features
* All modules are eventually built into one target 'foo' (foo.lib, foo.so, foo.dll).  
* This resulting target can be linked to by apps. 
* Individual modules can be turned on and off.
* Each module can have its own private dependencies.
* Builds and runs cross-platform with CMake (tested on Linux, macOS and Windows).
* ~~Builds documentation with Doxygen~~ ToDo
* Continuous Integration via Travis CI (free)
  * Automated building 
  * Automated testing
  * ~~Automated test code coverage analysis with Coveralls~~ ToDo
* Continuous Delivery via Travis CI (free)
  * ~~Automated deployment to GitHub project release~~ ToDo 

### Architecture
![Architecture](https://g.gravizo.com/svg?digraph%20G%20%7B%0A%20subgraph%20cluster_0%20%7B%0A%20foo%20-%3E%20core%3B%0A%20foo%20-%3E%20extension%3B%0A%20extension%20-%3E%20core%20%5Bstyle%3Ddashed%2C%20label%3Ddepends%2C%20fontcolor%3Ddimgray%2C%20color%3Ddimgray%5D%3B%0A%20%7B%20rank%3Dsame%20core%20extension%20%7D%0A%20label%20%3D%20%22FooLib%22%3B%0A%20labelloc%3Dt%3B%0A%20labeljust%3Dl%3B%0A%7D%0Aapp%20%5Blabel%3D%22Your%20app%22%2C%20shape%3Dbox%2C%20style%3Dfilled%2C%20fillcolor%3Dblack%2C%20fontcolor%3Dwhite%5D%3B%0Aapp%20-%3E%20foo%3B%0Adependency%20%5Blabel%3D%22dependency%22style%3Dfilled%2C%20fillcolor%3Dlightgrey%5D%3B%0Aextension%20-%3E%20dependency%20%5Bstyle%3Ddashed%2C%20label%3D%22%20%20%20depends%22%2C%20fontcolor%3Ddimgray%2C%20color%3Ddimgray%5D%3B%0A%7D)

### Project structure
* CMakeLists.txt
* foo - The library
  * CMakeLists.txt
  * foo.cpp
  * core - core module
    * CMakeLists.txt
    * include
      * (public header files)
    * src
      * (cpp files and private header files)
    * test
      * CMakeLists.txt
      * *.cpp - Unit test source code
  * extension - an extension module
    * (same structure as core module)
* apps - Example app using the library
  * CMakeLists.txt
  * fooapp.cpp - app source code
  
  # Usage
  ...
  
  # License
  This project is licensed under the GNU General Public License 3.0 - see the [LICENSE](LICENSE) file for details.
