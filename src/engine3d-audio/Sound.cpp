// #include "Sound.hpp"
#include <engine3d-audio/Sound.hpp>

namespace engine3d::audio{
    void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount){
        ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
        if (pDecoder == NULL) {
            return;
        }

        ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);

        (void)pInput;
    }

    Sound::Sound(const std::string& p_Filename){
        ma_decoder_init_file(p_Filename.c_str(), nullptr, &m_Decoder);

        m_AudioDeviceConfig = ma_device_config_init(ma_device_type_playback);

        m_AudioDeviceConfig.playback.format   = m_Decoder.outputFormat;
        m_AudioDeviceConfig.playback.channels = m_Decoder.outputChannels;
        m_AudioDeviceConfig.sampleRate        = m_Decoder.outputSampleRate;
        m_AudioDeviceConfig.dataCallback      = data_callback;
        m_AudioDeviceConfig.pUserData         = &m_Decoder;

        auto res = ma_device_init(nullptr, &m_AudioDeviceConfig, &m_AudioDeviceHandler);
        if(res != MA_SUCCESS){
            Cleanup();
            return;
        }
    }

    Sound::~Sound(){
        Cleanup();
    }

    void Sound::OnPlay(){
        auto res = ma_device_start(&m_AudioDeviceHandler);
        if(res != MA_SUCCESS){
            Cleanup();
        }
    }

    void Sound::OnStop(){
        auto res = ma_device_stop(&m_AudioDeviceHandler);
        
        if(res != MA_SUCCESS){
            Cleanup();
        }
    }

    void Sound::Cleanup(){
        ma_device_uninit(&m_AudioDeviceHandler);
        ma_decoder_uninit(&m_Decoder);
    }
};