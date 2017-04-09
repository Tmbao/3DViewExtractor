cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(2d_view_extractor)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(extractor 
    main.cpp
    camera_position.h
    off_helpers.h
    view_extractor.h
    view_provider.h
    view_provider_example.h
    utils.h)

target_link_libraries(extractor ${PCL_LIBRARIES})