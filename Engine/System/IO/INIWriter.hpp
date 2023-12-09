#ifndef ENGINE_SYSTEM_IO_INIWRITER_HPP
#define ENGINE_SYSTEM_IO_INIWRITER_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <fstream>
#include <map>
#include "Path.hpp"
#include "../IDisposable.hpp"
#include "../Types.hpp"

/// @brief INI 파일 작성 클래스
class INIWriter final : public IDisposable
{
private:
    std::map<std::string, std::map<std::string, std::string>> m_Maps;           //!< INI 데이터

public:
    INIWriter() noexcept;
    virtual ~INIWriter() noexcept;

    [[nodiscard]] bool Save(std::string_view filePath) noexcept;
    virtual void Dispose() noexcept override;

    void Write(std::string_view section, std::string_view key, const std::string& value) noexcept;
    void Write(std::string_view section, std::string_view key, int64_t value) noexcept;
    void Write(std::string_view section, std::string_view key, double value) noexcept;
    void Write(std::string_view section, std::string_view key, bool value) noexcept;
    bool Remove(std::string_view section, std::string_view key) noexcept;
};

#endif