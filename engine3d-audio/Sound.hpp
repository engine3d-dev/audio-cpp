#pragma once
#include <string>
#include <engine3d-audio/internal/miniaudio.h>

namespace engine3d::audio{
    /**
     * @note Sound abstraction around the miniaudio API
     * 
     */
    class Sound{
    public:
        Sound(const std::string& p_Filename);
        ~Sound();

        void OnPlay();
        void OnStop();
    private:
        void Cleanup();
    private:
        ma_decoder m_Decoder;
        ma_device m_AudioDeviceHandler;
        ma_device_config m_AudioDeviceConfig;
    };
};