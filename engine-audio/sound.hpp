#pragma once
#include <string>
#include <engine-audio/internal/miniaudio.h>

namespace audio{
    /**
     * @note Sound abstraction around the miniaudio API
     * 
     */
    class sound{
    public:
        sound(const std::string& p_filename);
        ~sound();

        void on_play();
        void on_stop();
    private:
        void cleanup();
    private:
        ma_decoder m_decoder;
        ma_device m_audio_device_handler;
        ma_device_config m_audio_device_config;
    };
};