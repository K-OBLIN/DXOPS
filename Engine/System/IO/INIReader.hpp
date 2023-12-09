#ifndef ENGINE_SYSTEM_IO_INIREADER_HPP
#define ENGINE_SYSTEM_IO_INIREADER_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <algorithm>
#include <fstream>
#include <unordered_map>
#include "Path.hpp"
#include "../IDisposable.hpp"
#include "../Types.hpp"

/// @brief INI 파일 읽기 클래스
class INIReader final : public IDisposable
{
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> m_UnorderedMaps;          //!< INI 데이터


    bool HasSection(std::string_view section) noexcept;
    bool HasKey(std::string_view section, std::string_view key) noexcept;

public:
    INIReader() noexcept;
    virtual ~INIReader() noexcept;

    [[nodiscard]] bool ReadINI(std::string_view filePath) noexcept;
    virtual void Dispose() noexcept override;

    std::string GetString(std::string_view section, std::string_view key, const std::string& defaultValue = "") noexcept;
    int64_t GetInteger(std::string_view section, std::string_view key, int64_t defaultValue = 0LL) noexcept;
    double GetDouble(std::string_view section, std::string_view key, double defaultValue = 0.0) noexcept;
    bool GetBoolean(std::string_view section, std::string_view key, bool defaultValue = 0.0) noexcept;
};

#endif