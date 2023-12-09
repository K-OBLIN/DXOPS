#include "StringUtils.hpp"

/// @brief 선행 공백 문자를 제거합니다.
/// @param str 문자열
void StringUtils::TrimStart(std::string& str) noexcept
{
    if (str.empty()) { return; }

    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) { return not std::isspace(ch); }));
}

/// @brief 후행 공백 문자를 제거합니다.
/// @param str 문자열
void StringUtils::TrimEnd(std::string& str) noexcept
{
    if (str.empty()) { return; }

    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return not std::isspace(ch); }).base(), str.end());
}

/// @brief 공백 문자를 제거합니다.
/// @param str 문자열
void StringUtils::Trim(std::string& str) noexcept
{
    TrimStart(str);
    TrimEnd(str);
}

/// @brief 구분자를 통해 문자열을 분리합니다.
/// @param str 문자열
/// @param delimiter 구분자
/// @return 성공(문자열 배열), 실패(std::nullopt)
Optional<std::vector<std::string>> StringUtils::Split(std::string_view str, char delimiter) noexcept
{
    if (str.empty())        { return std::nullopt; }
    if (delimiter == '\0')  { return std::nullopt; }

    std::istringstream iss(str.data());
    std::string buffer = "";
    std::vector<std::string> split;

    while (std::getline(iss, buffer, delimiter))
    {
        split.push_back(buffer);
    }

    return split;
}

/// @brief 대문자로 변환합니다.
/// @param str 문자열
void StringUtils::ToUpper(std::string& str) noexcept
{
    if (str.empty()) { return; }

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

/// @brief 소문자로 변환합니다.
/// @param str 문자열
void StringUtils::ToLower(std::string& str) noexcept
{
    if (str.empty()) { return; }

    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
