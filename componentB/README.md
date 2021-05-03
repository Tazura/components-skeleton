# componentB

## Description
This component is used for ....
* componentB-lib
  * Shared library for componentB
* componentB-slib
  * Static library for componentB

## Configuration
The configuration files are in /etc/componentB/

## Compiling
Required components: 
* boost
* fakeit
* gtest

Create an out of source build directory.
Then call cmake with the source directory.
```
cd componentB
mkdir build
cd build
cmake ..
make
```
