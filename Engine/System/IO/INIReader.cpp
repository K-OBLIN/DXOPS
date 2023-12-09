#include "INIReader.hpp"

/// @brief 생성자
INIReader::INIReader() noexcept
{

}

/// @brief 소멸자
INIReader::~INIReader() noexcept
{
    Dispose();
}

/// @brief INI 파일을 불러옵니다.
/// @param filePath 파일 경로
/// @return 성공(true), 실패(false)
bool INIReader::ReadINI(std::string_view filePath) noexcept
{
    if (filePath.empty())                       { return false; }
    if (not Path::Exists(filePath))             { return false; }
    if (Path::GetExtension(filePath) != ".ini") { return false; }

    // 불러오기 전, 자원 정리
    m_UnorderedMaps.clear();

    // 파일 읽기
    auto ifs = std::ifstream(filePath.data(), std::ifstream::in);
    if (not ifs.is_open())                      { return false; }

    // 변수
    std::string line;
    std::string section, key, value;

    // 한 줄씩 읽기
    auto length = 0;
    while (std::getline(ifs, line))
    {
        // 문자열 길이
        length = line.length();

        // 주석
        if (line[0] == '#') { continue; }
        // 섹션
        else if (line[0] == '[' and line[length - 1] == ']')
        {
            section = line.substr(1, length - 2);
        }
        // 키-값 쌍
        else
        {
            // 구분자 위치
            const auto delimiter_offset = line.find('=');

            // 키-값 쌍 찾기
            if (delimiter_offset != std::string::npos)
            {
                // 키
                key = line.substr(0, delimiter_offset);
                StringUtils::TrimEnd(key);

                // 값
                value = line.substr(delimiter_offset + 1);
                StringUtils::TrimStart(value);

                // 추가
                m_UnorderedMaps[section][key] = value;
                section = key = value = "";
            }
        }
    }

    ifs.close();

    return true;
}

/// @brief 자원을 정리합니다.
void INIReader::Dispose() noexcept
{
    m_UnorderedMaps.clear();
}

/// @brief 섹션을 가지고 있는지 확인합니다.
/// @param section 섹션명
/// @return 가지고 있음(true), 가지고 있지 않음(false)
bool INIReader::HasSection(std::string_view section) noexcept
{
    if (section.empty())            { return false; }
    if (m_UnorderedMaps.empty())    { return false; }

    return m_UnorderedMaps.find(section.data()) != m_UnorderedMaps.end();
}

/// @brief 키를 가지고 있는지 확인합니다.
/// @param section 섹션명
/// @param key 키명
/// @return 가지고 있음(true), 가지고 있지 않음(false)
bool INIReader::HasKey(std::string_view section, std::string_view key) noexcept
{
    if (section.empty() or key.empty()) { return false; }
    if (m_UnorderedMaps.empty())        { return false; }

    const auto _section = m_UnorderedMaps.find(section.data());
    if (_section != m_UnorderedMaps.end())
    {
        const auto key_value = _section->second;

        return key_value.find(key.data()) != key_value.end();
    }

    return false;
}

/// @brief 문자열 데이터를 취득합니다.
/// @param section 섹션명
/// @param key 키명
/// @param defaultValue 기본값
/// @return 성공(문자열 데이터), 실패(기본값)
std::string INIReader::GetString(std::string_view section, std::string_view key, const std::string& defaultValue) noexcept
{
    if (not HasSection(section))    { return defaultValue; }
    if (not HasKey(section, key))   { return defaultValue; }

    return m_UnorderedMaps[section.data()][key.data()];
}

/// @brief 정수형 데이터를 취득합니다.
/// @param section 섹션명
/// @param key 키명
/// @param defaultValue 기본값
/// @return 성공(정수형 데이터), 실패(기본값)
int64_t INIReader::GetInteger(std::string_view section, std::string_view key, int64_t defaultValue) noexcept
{
    return std::stoll(GetString(section, key, "0"));
}

/// @brief 실수형 데이터를 취득합니다.
/// @param section 섹션명
/// @param key 키명
/// @param defaultValue 기본값
/// @return 성공(실수형 데이터), 실패(기본값)
double INIReader::GetDouble(std::string_view section, std::string_view key, double defaultValue) noexcept
{
    return std::stod(GetString(section, key, "0.0"));
}

/// @brief Boolean 데이터를 취득합니다.
/// @param section 섹션명
/// @param key 키명
/// @param defaultValue 기본값
/// @return 성공(Boolean 데이터), 실패(기본값)
bool INIReader::GetBoolean(std::string_view section, std::string_view key, bool defaultValue) noexcept
{
    auto value = GetString(section, key, "false");
    if (value == "false") { return defaultValue; }

    StringUtils::ToLower(value);
    if ((value == "true") or (value == "on") or (value == "1"))
    {
        return true;
    }

    return defaultValue;
}