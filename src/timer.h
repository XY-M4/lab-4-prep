#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstdint>
class Timer {
public: // aliases for different time units
    using Nanos = std::chrono::nanoseconds;
    using Micros = std::chrono::microseconds;
    using Millis = std::chrono::milliseconds;
    using Seconds = std::chrono::seconds;
    using Minutes = std::chrono::minutes;
    using Hours = std::chrono::hours;

    Timer() {  // Constructor Default
        _start_time = std::chrono::steady_clock::now(); // start the timer on creation
    }

    void restart() {
        _start_time = std::chrono::steady_clock::now(); // restart the timer
    }

    // returns the amount of time since the last restart and then resets the timer
    template <typename T> uint64_t click() {
        auto current_time = std::chrono::steady_clock::now(); // restart the timer
        auto elapsed = std::chrono::duration_cast<T>(current_time - _start_time).count(); //duration
        _start_time = current_time; // reset start time
        return static_cast<uint64_t>(elapsed); //result
    }

    // returns the amount of time since the last click/restart without resetting the timer
    template <typename T> uint64_t glance() const {
        auto current_time = std::chrono::steady_clock::now(); // restart the timer
        auto elapsed = std::chrono::duration_cast<T>(current_time - _start_time).count(); //duration
        return static_cast<uint64_t>(elapsed); //result
    }

private:
    std::chrono::steady_clock::time_point _start_time; // stores when the timer was last started/reset
};

#endif  // TIMER_H
