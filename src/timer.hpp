#ifndef timer_hpp
#define timer_hpp

#include <iostream>
#include <chrono>

namespace bench
{
    class timer
    {
    public:

        void start();
        void stop();

        double deltatime();

    private:

        std::chrono::high_resolution_clock::time_point m_startTime;
        std::chrono::duration<double> m_deltaTime;
    };
}

#endif