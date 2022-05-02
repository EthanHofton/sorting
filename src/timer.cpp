#include "timer.hpp"

namespace bench
{
    void timer::start()
    {
        m_startTime = std::chrono::high_resolution_clock::now();
    }

    void timer::stop()
    {
        m_deltaTime = std::chrono::high_resolution_clock::now() - m_startTime;
    }

    double timer::deltatime()
    {
        return m_deltaTime.count();
    }
}