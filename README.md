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
./extractor <path-to-mesh> <output-folder>
# E.g.:
# ./extractor ../data/bus.off 
# ./extractor ../data/bus.off ../output
```
If `output-folder` is not specified, 2D outputs will be stored in the same folder with the mesh file.
