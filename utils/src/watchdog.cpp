/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file 
/// @author embotech AG
/// @date 03 Nov 2021
/// @brief Implementation of Watchdog class implementing a watchdog timer.

#include "watchdog.hpp"

obrttg::Watchdog::Watchdog() : Watchdog(0, nullptr) {}

obrttg::Watchdog::Watchdog(uint64_t duration) : Watchdog(duration, nullptr) {}

obrttg::Watchdog::Watchdog(uint64_t duration, std::function<void()> callback)
    : m_running(false), m_duration(duration), m_callback(callback) {}

obrttg::Watchdog::~Watchdog()
{
    stop();
}

int obrttg::Watchdog::setDuration(uint64_t duration)
{
    std::unique_lock<std::mutex> lk(m_mtx);
    if (!m_running)
    {
        m_duration = duration;
        return 0;
    }
    return 1;
}

int obrttg::Watchdog::setCallback(std::function<void()> callback)
{
    std::unique_lock<std::mutex> lk(m_mtx);
    if (!m_running)
    {
        m_callback = callback;
        m_init = false;
        return 0;
    }
    return 1;
}

int obrttg::Watchdog::start()
{
    std::unique_lock<std::mutex> lk(m_mtx);
    if (!m_init && initialize())
    {
        return 1;
    }

    if (!m_running && (m_duration > 0) && !arm())
    {
        m_running = true;
        return 0;
    }
    return 1;
}

bool obrttg::Watchdog::isRunning()
{
    std::unique_lock<std::mutex> lk(m_mtx);
    return m_running;
}

void obrttg::Watchdog::stop()
{
    std::unique_lock<std::mutex> lk(m_mtx);
    if (m_running && !disarm())
    {
        m_running = false;
    }
}

void obrttg::Watchdog::pet()
{
    std::unique_lock<std::mutex> lk(m_mtx);
    if (m_running)
    {
        arm();
    }
}

void obrttg::Watchdog::handler(sigval_t sigval)
{
    Watchdog *wdog = (Watchdog*) sigval.sival_ptr;
    if(wdog->m_callback != nullptr)
    {
        wdog->m_callback();
    }
}

int obrttg::Watchdog::initialize()
{
    sigevent sev;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    sched_param param;
    param.sched_priority = 99;
    pthread_attr_setschedparam(&attr, &param);

    sev.sigev_notify_attributes = &attr;
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = &handler;
    sev.sigev_signo = SIGUSR1;
    sev.sigev_value.sival_ptr = this;

    int rc = -1;
    if (!(rc = timer_create(CLOCK_MONOTONIC, &sev, &m_timerid)))
    {
        m_init = true;
    }
    return rc;
}

int obrttg::Watchdog::arm()
{
    itimerspec its;
    its.it_value.tv_sec = m_duration / (1000*1000);
    its.it_value.tv_nsec = m_duration % (1000*1000) * 1000;
    its.it_interval.tv_sec = 0; 
    its.it_interval.tv_nsec = 0;

    return timer_settime(m_timerid, 0, &its, NULL);
}

int obrttg::Watchdog::disarm()
{
    itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
        
    return timer_settime(m_timerid, 0, &its, NULL);
}