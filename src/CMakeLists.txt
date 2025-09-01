
set(AUDIO_INCLUDE_DIRS ../audio-cpp)
set(AUDIO_SRC_DIRS audio-cpp)

set(
    all_src
    ${AUDIO_SRC_DIRS}/utilities.cpp
    ${AUDIO_SRC_DIRS}/sound.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src}) 
