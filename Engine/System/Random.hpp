#ifndef ENGINE_SYSTEM_RANDOM_HPP
#define ENGINE_SYSTEM_RANDOM_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <random>
#include "Types.hpp"

/// @brief 32Bit 난수 생성 클래스
class Random32 final
{
public:
    static int32_t GetNumber(int32_t min, int32_t max, int32_t seed = -1) noexcept;
    static double GetNumber(double min, double max, int32_t seed = -1) noexcept;
    static bool GetBoolean(double p = 0.5) noexcept;
};

#endif