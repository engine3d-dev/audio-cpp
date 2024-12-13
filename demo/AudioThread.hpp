#pragma once
#include <thread>

namespace engine3d::audio{
    enum Status{
        IDLE, // idle status meaning doing nothing
        ACTIVE, // on/available
        INACTIVE // off/inavailable
    };

    class AudioThread{
    public:
        AudioThread();

        template<typename T, typename... Args>
        void Dispatch(const T& p_Func, const Args&&... args){
            m_Thread = new std::thread(std::forward<T>(p_Func), args...);
            m_Status = Status::ACTIVE;
        }

        void OnStart();
        Status IsActive();

    private:
        std::thread* m_Thread;
        Status m_Status;
    };
};