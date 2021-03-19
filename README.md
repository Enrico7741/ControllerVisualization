# Cross-Platform Controller Input Visualization

![Emulator Showcase](./emulator.gif)

## About


## Features


## Building from source
Follow the specific instructions for your platform after you have downloaded the project. 

### Linux/MacOS
Install the SDL2 headers, libraries and CMake. On Ubuntu you can use the apt package manager for this, on MacOS you can use [Brew](https://brew.sh/) or [MacPorts](https://www.macports.org/).
```
  # Ubuntu
  $ sudo apt install libsdl2-dev
  $ sudo apt install cmake
  
  # MacOS Brew
  $ sudo brew install SDL2
  $ sudo brew install cmake
```
Start the `build.sh` script to create the executable.
```
  $ ./build.sh
```
The executable will be placed in your build folder.
```
  $ ./build/controller
```

Please make sure that your data folder is in the same directory as the executable if you move it around.

### Windows
The build system expects the SDL2 headers and libraries in the subfolder `extern/SDL2-2.0.12`. If you have Python installed, you can download and extract everything by executing the Python script `setup-win32.py`. Otherwise you have to [download](https://www.libsdl.org/download-2.0.php) and extract the SDL2 development libraries by hand.

To install CMake you have to download the installer from the [official website](https://cmake.org/download/) and install it yourself.

After you have installed everything you have to run the `build.sh` script with a terminal. To start the program you need to search for the executable in your build folder. It depends on your compiler where exactly it is. You have to start the program with a terminal. Make sure that the data folder is in the same directory as the executable.

## To-do

## References

 ## Thanks to
