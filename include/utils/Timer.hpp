#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
  std::chrono::_V2::steady_clock::time_point StartTime = {};
  std::chrono::_V2::steady_clock::duration ElapsedTime = {};

public:
  bool IsRunning() const;

  void Start();

  void Stop();

  void Reset();

  std::chrono::_V2::steady_clock::duration GetElapsed();

  int diffWithCurrent(std::chrono::_V2::steady_clock::duration d);

  int time();

  static int diff(std::chrono::_V2::steady_clock::duration d1, std::chrono::_V2::steady_clock::duration d2);
};

#endif