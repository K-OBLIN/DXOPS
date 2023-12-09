#ifndef ENGINE_SYSTEM_IO_BINARYWRITER_HPP
#define ENGINE_SYSTEM_IO_BINARYWRITER_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <algorithm>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include "Path.hpp"
#include "../IDisposable.hpp"
#include "../Types.hpp"

/// @brief 바이너리 파일 쓰기 클래스
class BinaryWriter final : public IDisposable
{
private:
    std::ofstream m_ofs;            //!< 파일 스트림

public:
    BinaryWriter() noexcept;
    explicit BinaryWriter(std::string_view filePath) noexcept;
    virtual ~BinaryWriter() noexcept;

    bool IsOpen() noexcept;
    virtual void Dispose() noexcept override;

    void Write(char value) noexcept;
    void Write(bool value) noexcept;
    void Write(sbyte_t value) noexcept;
    void Write(byte_t value) noexcept;
    void Write(int16_t value) noexcept;
    void Write(uint16_t value) noexcept;
    void Write(int32_t value) noexcept;
    void Write(uint32_t value) noexcept;
    void Write(int64_t value) noexcept;
    void Write(uint64_t value) noexcept;
    void Write(float value) noexcept;
    void Write(double value) noexcept;
    void Write(std::string_view str) noexcept;
    void Write(std::string_view str, size_t length) noexcept;
    void Write(const std::vector<char>& value) noexcept;
    void Write(const std::vector<byte_t>& value) noexcept;
};

#endif