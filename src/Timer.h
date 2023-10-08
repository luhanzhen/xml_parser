//
// Created by zhenl on 2022/9/6.
//

#ifndef XMLPARSER_TIMER_H
#define XMLPARSER_TIMER_H

#include<chrono>

class Timer {
public:
    Timer() : m_begin(std::chrono::high_resolution_clock::now()) {};

    void reset() { m_begin = std::chrono::high_resolution_clock::now(); };

    //默认输出毫秒
    [[nodiscard]] int64_t elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    [[nodiscard]] int64_t elapsed_micro() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //纳秒
    [[nodiscard]] int64_t elapsed_nano() const {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //秒
    [[nodiscard]] int64_t elapsed_seconds() const {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //分
    [[nodiscard]] int64_t elapsed_minutes() const {
        return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //时
    [[nodiscard]] int64_t elapsed_hours() const {
        return std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
};

#endif //XMLPARSER_TIMER_H



//using namespace std;
//using namespace std::chrono;

//	//默认输出秒
//	double elapsed() const {
//		return duration_cast<duration<double>>(high_resolution_clock::now() - m_begin).count();
//	}
