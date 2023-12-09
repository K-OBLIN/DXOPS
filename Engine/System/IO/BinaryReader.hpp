#ifndef ENGINE_SYSTEM_IO_BINARYREADER_HPP
#define ENGINE_SYSTEM_IO_BINARYREADER_HPP

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
#include "../Optional.hpp"
#include "../Types.hpp"

/// @brief 바이너리 읽기 클래스
class BinaryReader final : public IDisposable
{
private:
    std::ifstream m_ifs;            //!< 파일 스트림

public:
    BinaryReader() noexcept;
    explicit BinaryReader(std::string_view filePath) noexcept;
    virtual ~BinaryReader() noexcept;

    bool IsOpen() noexcept;
    virtual void Dispose() noexcept override;

    Optional<size_t> GetOffset() noexcept;
    Optional<size_t> GetSize() noexcept;

    void SetOffset(size_t offset) noexcept;

    Optional<char> ReadChar() noexcept;
    Optional<bool> ReadBoolean() noexcept;
    Optional<sbyte_t> ReadSByte() noexcept;
    Optional<byte_t> ReadByte() noexcept;
    Optional<int16_t> ReadInt16() noexcept;
    Optional<uint16_t> ReadUInt16() noexcept;
    Optional<int32_t> ReadInt32() noexcept;
    Optional<uint32_t> ReadUInt32() noexcept;
    Optional<int64_t> ReadInt64() noexcept;
    Optional<uint64_t> ReadUInt64() noexcept;
    Optional<float> ReadSingle() noexcept;
    Optional<double> ReadDouble() noexcept;
    Optional<std::string> ReadString() noexcept;
    void ReadString(std::string& str, size_t length) noexcept;
};

#endif