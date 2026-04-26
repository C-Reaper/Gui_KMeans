# Project README

## Overview
This project is a simple GUI application for visualizing the K-Means clustering algorithm. It provides an interactive interface to demonstrate how data points are grouped into clusters based on their proximity.

## Features
- Visual representation of K-Means clustering.
- Interactive UI to set the number of clusters (K).
- Real-time updates as new data points are added or existing ones moved.
- Different colors for each cluster to visually distinguish them.
- Save and load datasets for consistent testing.

## Project Structure
### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- X11 library for GUI functionality

### Build & Run
To build the project on Linux:
```sh
cd <Project>
make -f Makefile.linux all
make -f Makefile.linux exe
```

To run the built application:
```sh
./build/Main
```

For Windows (using MinGW-w64):
```sh
cd <Project>
make -f Makefile.windows all
make -f Makefile.windows exe
```

To run the built application on Windows:
```sh
build\Main.exe
```

For Emscripten (for web):
```sh
cd <Project>
make -f Makefile.web all
make -f Makefile.web exe
```

Then open `build/index.html` in a web browser.

For Wine (Linux cross compile for Windows):
```sh
cd <Project>
make -f Makefile.wine all
make -f Makefile.wine exe
```

To run the built application:
```sh
wine build/Main.exe
```

This README provides a concise overview of the project, its features, and how to build and run it on different platforms.