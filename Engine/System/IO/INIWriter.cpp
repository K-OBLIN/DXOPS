#include "INIWriter.hpp"

/// @brief 생성자
INIWriter::INIWriter() noexcept
{

}

/// @brief 소멸자
INIWriter::~INIWriter() noexcept
{
    Dispose();
}

/// @brief INI 파일을 작성합니다.
/// @param filePath 파일 경로
/// @return 성공(true), 실패(false)
bool INIWriter::Save(std::string_view filePath) noexcept
{
    if (filePath.empty())                       { return false; }
    if (Path::GetExtension(filePath) != ".ini") { return false; }
    if (m_Maps.empty())                         { return false; }

    // 작성
    auto ofs = std::ofstream(filePath.data(), std::ofstream::out);
    if (not ofs.is_open())                      { return false; }

    for (const auto& map : m_Maps)
    {
        // 섹션
        ofs << "[" << map.first << "]\n";

        // 키-값 쌍
        for (const auto& key_value : map.second)
        {
            ofs << key_value.first << " = " << key_value.second << "\n";
        }
        ofs << "\n";
    }

    ofs.close();

    return true;
}

/// @brief 자원을 정리합니다.
void INIWriter::Dispose() noexcept
{
    m_Maps.clear();
}

/// @brief 문자열 데이터를 추가합니다.
/// @param section 섹션명
/// @param key 키명
/// @param value 데이터
void INIWriter::Write(std::string_view section, std::string_view key, const std::string& value) noexcept
{
    if (section.empty() or key.empty()) { return; }

    m_Maps[section.data()][key.data()] = value;
}

/// @brief 정수 데이터를 추가합니다.
/// @param section 섹션명
/// @param key 키명
/// @param value 데이터
void INIWriter::Write(std::string_view section, std::string_view key, int64_t value) noexcept
{
    Write(section, key, std::to_string(value));
}

/// @brief 실수 데이터를 추가합니다.
/// @param section 섹션명
/// @param key 키명
/// @param value 데이터
void INIWriter::Write(std::string_view section, std::string_view key, double value) noexcept
{
    Write(section, key, std::to_string(value));
}

/// @brief Boolean 데이터를 추가합니다.
/// @param section 섹션명
/// @param key 키명
/// @param value 데이터
void INIWriter::Write(std::string_view section, std::string_view key, bool value) noexcept
{
    Write(section, key, std::to_string(value));
}

/// @brief 데이터를 제거합니다.
/// @param section 섹션명
/// @param key 키명
/// @return 성공(true), 실패(false)
bool INIWriter::Remove(std::string_view section, std::string_view key) noexcept
{
    if (section.empty() or key.empty()) { return false; }

    const auto _section = m_Maps.find(section.data());
    if (_section == m_Maps.end())       { return false; }

    auto& inner_map = _section->second;
    const auto keyIter = inner_map.find(key.data());
    if (keyIter == inner_map.end())     { return false; }

    inner_map.erase(keyIter);
    
    return true;
}