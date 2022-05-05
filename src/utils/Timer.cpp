#include "utils/Timer.hpp"


bool Timer::IsRunning() const {
    return StartTime != std::chrono::_V2::steady_clock::time_point{};
}

void Timer::Start() {
    if(!IsRunning()) {
        StartTime = std::chrono::_V2::steady_clock::now();
    }
}

void Timer::Stop() {
    if(IsRunning()) {
        ElapsedTime += std::chrono::_V2::steady_clock::now() - StartTime;
        StartTime = {};
    }
}

void Timer::Reset() {
    StartTime = {};
    ElapsedTime = {};
}

std::chrono::_V2::steady_clock::duration Timer::GetElapsed() {
    auto result = ElapsedTime;
    if(IsRunning()) {
        result += std::chrono::_V2::steady_clock::now() - StartTime;
    }
    return result;
}

int Timer::diffWithCurrent(std::chrono::_V2::steady_clock::duration d) {
    return time() -
        std::chrono::duration_cast<std::chrono::milliseconds>(d).count() ;
}

int Timer::time() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(GetElapsed()).count();
}

int Timer::diff(std::chrono::_V2::steady_clock::duration d1, std::chrono::_V2::steady_clock::duration d2) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(d1).count() 
        - std::chrono::duration_cast<std::chrono::milliseconds>(d2).count();
}