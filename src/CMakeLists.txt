
set(AUDIO_INCLUDE_DIRS ../engine3d-audio)
set(AUDIO_SRC_DIRS engine3d-audio)

set(
    all_headers
    ${AUDIO_INCLUDE_DIRS}/helper-functions.hpp
    ${AUDIO_INCLUDE_DIRS}/internal/miniaudio.h
    ${AUDIO_INCLUDE_DIRS}/Sound.hpp
)

set(
    all_src
    ${AUDIO_SRC_DIRS}/helper-functions.cpp
    ${AUDIO_SRC_DIRS}/internal/miniaudio.cpp
    ${AUDIO_SRC_DIRS}/Sound.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src}) 
