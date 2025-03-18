#pragma once
#include <miniaudio/miniaudio.h>

namespace audio {
    class device_enumeration {
    public:
        device_enumeration() {
            ma_context test_context;
            if(ma_context_init(nullptr, 0, nullptr, &test_context) != MA_SUCCESS) {

            }
        }

    };
};