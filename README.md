# 2D View Extractor
This is a tool to extract views from 3d mesh using PCL.

## Requrements
- CMake 3.0 or newer.
- PCL 1.8 or newer.

## How to build 
Make sure that you have CMake and PCL installed.
```
git clone https://github.com/Tmbao/2d_view_extractor.git
cd 2d_view_extractor
mkdir build
cd build
cmake ..
make
```

## How to run
```
./extractor <path-to-mesh>
# E.g.:
./extractor ../data/bus.off
```
2D views will be available in the same folder with the mesh file.
