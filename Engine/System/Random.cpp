#include "Random.hpp"

/// @brief 정수형 난수를 취득합니다.
/// @param min 최솟값
/// @param max 최댓값
/// @param seed 시드
/// @return 정수형 난수
/// @note 최솟값과 최댓값을 포함하여 취득합니다.
int32_t Random32::GetNumber(int32_t min, int32_t max, int32_t seed) noexcept
{
    if (seed <= -1)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int32_t> uid(min, max);

        return uid(gen);
    }

    std::mt19937 gen(seed);
    std::uniform_int_distribution<int32_t> uid(min, max);

    return uid(gen);
}

/// @brief 실수형 난수를 취득합니다.
/// @param min 최솟값
/// @param max 최댓값
/// @param seed 시드
/// @return 실수형 난수
/// @note 최솟값과 최댓값을 포함하여 취득합니다.
double Random32::GetNumber(double min, double max, int32_t seed) noexcept
{
    if (seed <= -1)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> uid(min, max);

        return uid(gen);
    }

    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> uid(min, max);

    return uid(gen);
}

/// @brief Boolean 값을 취득합니다.
/// @param p 확률 (0.0 ~ 1.0)
/// @return true 또는 false
bool Random32::GetBoolean(double p) noexcept
{
    p = (p < 0.0) ? 0.0 : ((p > 1.0) ? 1.0 : p);

    std::random_device rd;
    std::mt19937 gen(rd());

    return std::bernoulli_distribution(p)(gen);
}