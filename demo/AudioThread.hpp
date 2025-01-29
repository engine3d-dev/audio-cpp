#pragma once
#include <thread>
#include <memory>

namespace engine3d::audio{
    enum ThreadStatus{
        IDLE, // idle status meaning doing nothing
        ACTIVE, // on/available
        INACTIVE // off/inavailable
    };

    /**
     * @name Audio Thread
     * @note Dedicated thread for processing audio inputs
     * TODO: Experiemental. Still need some work
    */
    class AudioThread{
    public:
        AudioThread(){}

        template<typename T, typename... Args>
        void Dispatch(const T& p_Func, const Args&&... args){
            m_Thread = std::make_shared<std::thread>(std::forward<T>(p_Func), args...);
            m_Status = ThreadStatus::ACTIVE;
        }

        void OnStart();
        ThreadStatus IsActive();

    private:
        std::shared_ptr<std::thread> m_Thread;
        ThreadStatus m_Status;
    };
};