#ifndef ENGINE_SYSTEM_OPTIONAL_HPP
#define ENGINE_SYSTEM_OPTIONAL_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <optional>

/// @brief Optional
/// @tparam T 데이터 형식
/// @note 기본값을 반환하기에는 좀 애매한 상황이고, 데이터가 없음을 나타날 때 사용합니다.
template <typename T>
using Optional = std::optional<T>;

#endif