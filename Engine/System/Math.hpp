#ifndef ENGINE_SYSTEM_MATH_HPP
#define ENGINE_SYSTEM_MATH_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <cmath>
#include <numbers>

/// @brief 수학 클래스
class Math final 
{
public:
    static constexpr double PI         = std::numbers::pi;         //!< PI
    static constexpr double TWO_PI     = PI * 2.0;                 //!< PI × 2
    static constexpr double HALF_PI    = PI / 2.0;                 //!< PI ÷ 2

    /// @brief Radian으로 변환합니다.
    /// @param degree Degree
    /// @return Radian
    static inline constexpr double ToRadian(double degree) noexcept
    {
        return degree * (PI / 180.0);
    }

    /// @brief Degree로 변환합니다.
    /// @param radian Radian
    /// @return Degree
    static inline constexpr double ToDegree(double radian) noexcept
    {
        return radian * (180.0 / PI);
    }
};

#endif