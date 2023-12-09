#include "BinaryWriter.hpp"

/// @brief 생성자
BinaryWriter::BinaryWriter() noexcept
{
    
}

/// @brief 생성자
/// @param filePath 파일 경로
BinaryWriter::BinaryWriter(std::string_view filePath) noexcept
{
    if (filePath.empty()) { return; }

    // 불러오기 전, 자원 정리
    if (m_ofs)
    {
        if (m_ofs.is_open())
        {
            m_ofs.close();
        }
    }

    // 불러오기
    m_ofs = std::ofstream(filePath.data(), std::ofstream::out | std::ofstream::binary);
    if (not m_ofs.is_open()) { return; }
}

/// @brief 소멸자
BinaryWriter::~BinaryWriter() noexcept
{
    Dispose();
}

/// @brief 파일 쓰기를 성공적으로 수행할 수 있는지 확인합니다.
/// @return 성공(true), 실패(false)
bool BinaryWriter::IsOpen() noexcept
{
    if (not m_ofs) { return false; }

    return m_ofs.is_open();
}

/// @brief 자원을 정리합니다.
void BinaryWriter::Dispose() noexcept
{
    if (m_ofs)
    {
        if (m_ofs.is_open())
        {
            m_ofs.close();
        }
    }
}

/// @brief 문자 데이터를 작성합니다.
/// @param value 문자 데이터
void BinaryWriter::Write(char value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief Boolean 데이터를 작성합니다.
/// @param value Boolean 데이터
void BinaryWriter::Write(bool value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 있는 8비트 정수형 데이터를 작성합니다.
/// @param value 부호 있는 8비트 정수형 데이터
void BinaryWriter::Write(sbyte_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 없는 8비트 정수형 데이터를 작성합니다.
/// @param value 부호 없는 8비트 정수형 데이터
void BinaryWriter::Write(byte_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 있는 16비트 정수형 데이터를 작성합니다.
/// @param value 부호 있는 16비트 정수형 데이터
void BinaryWriter::Write(int16_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 없는 16비트 정수형 데이터를 작성합니다.
/// @param value 부호 없는 16비트 정수형 데이터
void BinaryWriter::Write(uint16_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 있는 32비트 정수형 데이터를 작성합니다.
/// @param value 부호 있는 32비트 정수형 데이터
void BinaryWriter::Write(int32_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 없는 32비트 정수형 데이터를 작성합니다.
/// @param value 부호 없는 32비트 정수형 데이터
void BinaryWriter::Write(uint32_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 있는 64비트 정수형 데이터를 작성합니다.
/// @param value 부호 있는 64비트 정수형 데이터
void BinaryWriter::Write(int64_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 부호 없는 64비트 정수형 데이터를 작성합니다.
/// @param value 부호 없는 64비트 정수형 데이터
void BinaryWriter::Write(uint64_t value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 32비트 부동 소수점 데이터를 작성합니다.
/// @param value 32비트 부동 소수점 데이터
void BinaryWriter::Write(float value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 64비트 부동 소수점 데이터를 작성합니다.
/// @param value 64비트 부동 소수점 데이터
void BinaryWriter::Write(double value) noexcept
{
    if (not IsOpen()) { return; }

    m_ofs << value;
}

/// @brief 문자열 데이터를 작성합니다.
/// @param value 문자열 데이터
void BinaryWriter::Write(std::string_view value) noexcept
{
    if (not IsOpen())   { return; }
    if (value.empty())  { return; }

    m_ofs << value;
    m_ofs << 0x00;
}

/// @brief 문자열 데이터를 작성합니다.
/// @param value 문자열 데이터
/// @param length 작성하는 데이터의 수 (문자열의 길이와 같지 않아도 됨)
void BinaryWriter::Write(std::string_view value, size_t length) noexcept
{
    if (not IsOpen())   { return; }
    if (value.empty())  { return; }

    const auto str_length = value.length();
    for (auto i = size_t(0); i < length; ++i)
    {
        m_ofs << (i > str_length) ? 0x00 : value[i];
    }
}

/// @brief 문자 배열을 작성합니다.
/// @param value 문자 배열
void BinaryWriter::Write(const std::vector<char>& value) noexcept
{
    if (not IsOpen())   { return; }
    if (value.empty())  { return; }

    for (const auto& val : value)
    {
        m_ofs << val;
    }
}

/// @brief 부호 없는 8비트 정수형 배열을 작성합니다.
/// @param value 부호 없는 8비트 정수형 배열
void BinaryWriter::Write(const std::vector<byte_t>& value) noexcept
{
    if (not IsOpen())   { return; }
    if (value.empty())  { return; }

    for (const auto& val : value)
    {
        m_ofs << val;
    }
}