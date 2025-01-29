cmake_minimum_required(VERSION 3.15)
project(demo CXX)

build_application(
    SOURCES
    application.cpp
    
    PACKAGES
    engine3d-audio
    
    LINK_PACKAGES
    engine3d-audio::engine3d-audio
)
