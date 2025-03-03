cmake_minimum_required(VERSION 3.15)
project(demo CXX)

build_application(
    SOURCES
    application.cpp
    
    PACKAGES
    engine-audio
    
    LINK_PACKAGES
    engine-audio::engine-audio
)
