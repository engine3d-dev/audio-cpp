cmake_minimum_required(VERSION 3.25)
project(engine-audio LANGUAGES C CXX)

build_library(
    DIRECTORIES src

    ENABLE_TESTS ON

    UNIT_TEST_SOURCES
    tests/main.test.cpp
    tests/basic_audio.test.cpp
    
    PACKAGES
    miniaudio

    LINK_PACKAGES
    miniaudio::miniaudio
)

generate_compile_commands()

target_include_directories(${PROJECT_NAME} PUBLIC ./)
target_include_directories(${PROJECT_NAME} PRIVATE audio audio/internal)