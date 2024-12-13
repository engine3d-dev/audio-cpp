#pragma once

#include <span>
#include <string>

namespace engine3d::audio{
    /**
    * @note Audio Reader takes in any type of audio file.
    * @note Using this API allows you to control how you read in that data.
    * @note Such as ReadInt, ReadAs<T>, ReadFloat, ReadString, etc.
    * 
    */
    class AudioReader{
    public:
        AudioReader(const std::string& p_Filename);

        bool IsFileValid() const { return m_IsAudioFileValid; }

        //! @note We are reading data from a specified audio file
        //! @param p_Filename is the location of the audiofile we are reading from.
        //! @note Basically should allow us to read in those files and play them.
        static std::span<uint8_t> Read(const std::string& p_Filename);

        template<typename T>
        T ReadAs(){
        }

    private:
        bool m_IsAudioFileValid;
    };
};