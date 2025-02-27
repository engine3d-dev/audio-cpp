// #include "sound.hpp"
#include <engine-audio/sound.hpp>

namespace audio{
    void data_callback(ma_device* p_device, void* p_output, const void* p_input, ma_uint32 p_frame_count){
        ma_decoder* pDecoder = (ma_decoder*)p_device->pUserData;
        if (pDecoder == NULL) {
            return;
        }

        ma_decoder_read_pcm_frames(pDecoder, p_output, p_frame_count, NULL);

        (void)p_input;
    }

    sound::sound(const std::string& p_filename){
        ma_decoder_init_file(p_filename.c_str(), nullptr, &m_decoder);

        m_audio_device_config = ma_device_config_init(ma_device_type_playback);

        m_audio_device_config.playback.format   = m_decoder.outputFormat;
        m_audio_device_config.playback.channels = m_decoder.outputChannels;
        m_audio_device_config.sampleRate        = m_decoder.outputSampleRate;
        m_audio_device_config.dataCallback      = data_callback;
        m_audio_device_config.pUserData         = &m_decoder;

        auto res = ma_device_init(nullptr, &m_audio_device_config, &m_audio_device_handler);
        if(res != MA_SUCCESS){
            cleanup();
            return;
        }
    }

    sound::~sound(){
        cleanup();
    }

    void sound::on_play(){
        auto res = ma_device_start(&m_audio_device_handler);
        if(res != MA_SUCCESS){
            cleanup();
        }
    }

    void sound::on_stop(){
        auto res = ma_device_stop(&m_audio_device_handler);
        
        if(res != MA_SUCCESS){
            cleanup();
        }
    }

    void sound::cleanup(){
        ma_device_uninit(&m_audio_device_handler);
        ma_decoder_uninit(&m_decoder);
    }
};