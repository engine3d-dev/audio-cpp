#pragma once

#include <span>
#include <string>
#include <cstdint>

namespace audio {
    /**
     * @note Audio Reader takes in any type of audio file.
     * @note Using this API allows you to control how you read in that data.
     * @note Such as ReadInt, ReadAs<T>, ReadFloat, ReadString, etc.
     *
     */
    class audio_reader {
    public:
        audio_reader(const std::string& p_filename);

        bool is_valid() const { return m_is_audio_stream_valid; }

        //! @note We are reading data from a specified audio file
        //! @param p_Filename is the location of the audiofile we are reading
        //! from.
        //! @note Basically should allow us to read in those files and play
        //! them.
        static std::span<uint8_t> read(const std::string& p_filename);

        template<typename T>
        T ReadAs() {}

    private:
        bool m_is_audio_stream_valid = false;
    };
};