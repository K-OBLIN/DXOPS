#include "BinaryReader.hpp"

/// @brief 생성자
BinaryReader::BinaryReader() noexcept 
{
    
}

/// @brief 생성자
/// @param filePath 파일 경로
BinaryReader::BinaryReader(std::string_view filePath) noexcept 
{
    if (filePath.empty()) 
    {
        return;
    }
    if (not Path::Exists(filePath)) 
    {
        return;
    }

    // 불러오기 전, 자원 정리
    if (m_ifs)
    {
        if (m_ifs.is_open())
        {
            m_ifs.close();
        }
    }

    // 불러오기
    m_ifs = std::ifstream(filePath.data(), std::ifstream::in | std::ifstream::binary);
    if (not m_ifs.is_open()) { return; }
}

/// @brief 소멸자
BinaryReader::~BinaryReader() noexcept 
{
    Dispose();
}

/// @brief 자원을 정리합니다.
void BinaryReader::Dispose() noexcept 
{
    if (m_ifs)
    {
        if (m_ifs.is_open())
        {
            m_ifs.close();
        }
    }
}

/// @brief 성공적으로 파일을 열었는지 확인합니다.
/// @return true 또는 false
bool BinaryReader::IsOpen() noexcept 
{
    if (not m_ifs) { return false; }

    return m_ifs.is_open();
}

/// @brief 오프셋을 취득합니다.
/// @return 오프셋 또는 std::nullopt
Optional<size_t> BinaryReader::GetOffset() noexcept 
{
    if (not IsOpen()) { return std::nullopt; }

    return m_ifs.tellg();
}

/// @brief 파일의 크기를 취득합니다.
/// @return 파일의 크기 또는 std::nullopt
Optional<size_t> BinaryReader::GetSize() noexcept 
{
    if (not IsOpen()) { return std::nullopt; }

    auto backup = GetOffset();

    m_ifs.seekg(0, std::ifstream::end);

    auto size = GetOffset();

    m_ifs.seekg(backup.value_or(0), std::ifstream::beg);

    return size.value_or(0);
}

/// @brief 오프셋을 설정합니다.
/// @param offset 오프셋
void BinaryReader::SetOffset(size_t offset) noexcept 
{
    if (not m_ifs.is_open())    { return; }
    if (offset > GetSize())     { return; }

    m_ifs.seekg(offset, std::ifstream::beg);
}

/// @brief 문자 데이터를 읽어옵니다.
/// @return 문자 또는 std::nullopt
Optional<char> BinaryReader::ReadChar() noexcept
 {
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = char(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief Boolean 데이터를 읽어옵니다.
/// @return Boolean 또는 std::nullopt
Optional<bool> BinaryReader::ReadBoolean() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = bool(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief SByte 데이터를 읽어옵니다.
/// @return SByte 또는 std::nullopt
Optional<sbyte_t> BinaryReader::ReadSByte() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = sbyte_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief Byte 데이터를 읽어옵니다.
/// @return Byte 또는 std::nullopt
Optional<byte_t> BinaryReader::ReadByte() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = byte_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief Int16 데이터를 읽어옵니다.
/// @return Int16 또는 std::nullopt
Optional<int16_t> BinaryReader::ReadInt16() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = int16_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief UInt16 데이터를 읽어옵니다.
/// @return UInt16 또는 std::nullopt
Optional<uint16_t> BinaryReader::ReadUInt16() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = uint16_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief Int32 데이터를 읽어옵니다.
/// @return Int32 또는 std::nullopt
Optional<int32_t> BinaryReader::ReadInt32() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = int32_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief UInt32 데이터를 읽어옵니다.
/// @return UInt32 또는 std::nullopt
Optional<uint32_t> BinaryReader::ReadUInt32() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = uint32_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief Int64 데이터를 읽어옵니다.
/// @return Int64 또는 std::nullopt
Optional<int64_t> BinaryReader::ReadInt64() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = int64_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief UInt64 데이터를 읽어옵니다.
/// @return UInt64 또는 std::nullopt
Optional<uint64_t> BinaryReader::ReadUInt64() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = uint64_t(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief float 데이터를 읽어옵니다.
/// @return float 또는 std::nullopt
Optional<float> BinaryReader::ReadSingle() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = float(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief double 데이터를 읽어옵니다.
/// @return double 또는 std::nullopt
Optional<double> BinaryReader::ReadDouble() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    auto buf = double(0);
    m_ifs.read((char*)&buf, sizeof(buf));
    return buf;
}

/// @brief 문자열 데이터를 읽어옵니다.
/// @return 문자열 또는 std::nullopt
Optional<std::string> BinaryReader::ReadString() noexcept 
{
    if (not IsOpen())   { return std::nullopt; }
    if (m_ifs.eof())    { return std::nullopt; }

    std::vector<char> chars;
    auto peek = m_ifs.peek();
    char buf;
    while ((peek != EOF) and (peek != '\0')) {
        m_ifs.get(buf);
        chars.push_back(buf);

        peek = m_ifs.peek();
    }

    return std::string(chars.begin(), chars.end());
}

/// @brief 문자열 데이터를 읽어옵니다.
/// @param str 문자열
/// @param length 길이
void BinaryReader::ReadString(std::string& str, size_t length) noexcept 
{
    if (not m_ifs.is_open())    { return; }
    if (m_ifs.eof())            { return; }
    if (length > GetSize())     { return; }

    auto buf = new char[length];
    m_ifs.read((char*)buf, length);

    str.assign(buf);

    delete[] buf;
}