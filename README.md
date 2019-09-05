# Modular C++ library with CMake [![Build Status](https://travis-ci.org/martijnkoopman/Modular-Cpp-library.svg?branch=master)](https://travis-ci.org/martijnkoopman/Modular-Cpp-library) [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## What' this?
This repository is a template for a modular C++ library.

### Features
* All modules are eventually build into one target 'foo' (foo.lib, foo.so, foo.dll).  
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
...

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
  This project is licensed under the Apache License 2.0 - see the [LICENSE.md](LICENSE.md) file for details.
