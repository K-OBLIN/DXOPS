#ifndef ENGINE_SYSTEM_STRINGUTILS_HPP
#define ENGINE_SYSTEM_STRINGUTILS_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <algorithm>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include "Optional.hpp"

/// @brief 문자열 유틸 클래스
class StringUtils final
{
public:
    static void TrimStart(std::string& str) noexcept;
    static void TrimEnd(std::string& str) noexcept;
    static void Trim(std::string& str) noexcept;
    static Optional<std::vector<std::string>> Split(std::string_view str, char delimiter) noexcept;
    static void ToUpper(std::string& str) noexcept;
    static void ToLower(std::string& str) noexcept;
};

#endif
