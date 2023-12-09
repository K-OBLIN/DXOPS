#include "Path.hpp"

/// @brief 파일의 확장자명을 변경합니다.
/// @param path 파일 경로
/// @param extension 새 확장자명
void Path::ChangeExtension(std::string& path, std::string_view extension) noexcept
{
    if (path.empty() or extension.empty()) { return; }

    path = std::filesystem::path(path).replace_extension(extension).generic_string();
}

/// @brief 파일명을 변경합니다.
/// @param path 파일 경로
/// @param fileName 새 파일명
void Path::ChangeFileName(std::string& path, std::string_view fileName) noexcept
{
    if (path.empty() or fileName.empty()) { return; }

    path = std::filesystem::path(path).replace_filename(fileName).generic_string();
}

/// @brief 하나의 경로로 결합합니다.
/// @param paths 경로 배열
/// @return 성공(경로 문자열), 실패(std::nullopt)
Optional<std::string> Path::Combine(const std::vector<std::string>& paths) noexcept
{
    if (paths.empty()) { return std::nullopt; }

    std::filesystem::path p;
    for (const auto& path : paths)
    {
        p /= path;
    }

    return p.generic_string();
}

/// @brief 파일 또는 디렉토리가 존재하는지 확인합니다.
/// @param path 파일 또는 디렉토리 경로
/// @return 존재(true), 미존재(false)
bool Path::Exists(std::string_view path) noexcept
{
    return std::filesystem::exists(path);
}

/// @brief 디렉토리명을 취득합니다.
/// @param path 디렉토리 경로
/// @return 성공(디렉토리명), 실패(std::nullopt)
Optional<std::string> Path::GetDirectoryName(std::string_view path) noexcept
{
    if (path.empty()) { return std::nullopt; }

    return std::filesystem::path(path).parent_path().generic_string();
}

/// @brief 확장자명을 취득합니다.
/// @param path 파일 경로
/// @return 성공(확장자명), 실패(std::nullopt)
Optional<std::string> Path::GetExtension(std::string_view path) noexcept
{
    if (path.empty()) { return std::nullopt; }

    const auto p = std::filesystem::path(path);
    if (p.has_extension())
    {
        return p.extension().generic_string();
    }

    return std::nullopt;
}

/// @brief 파일명을 취득합니다.
/// @param path 파일 경로
/// @return 성공(파일명), 실패(std::nullopt)
/// @note 확장자명이 포함된 파일명입니다.
Optional<std::string> Path::GetFileName(std::string_view path) noexcept
{
    if (path.empty()) { return std::nullopt; }

    auto file_name = std::filesystem::path(path).filename();
    const auto extension = GetExtension(path);
    if (extension.has_value())
    {
        return file_name.append(extension.value()).string();
    }

    return std::nullopt;
}

/// @brief 확장자명을 제외한 파일명을 취득합니다.
/// @param path 파일 경로
/// @return 성공(확장자명이 제외된 파일명), 실패(std::nullopt)
Optional<std::string> Path::GetFileNameWithoutExtension(std::string_view path) noexcept
{
    if (path.empty()) { return std::nullopt; }

    const auto file_name = std::filesystem::path(path).filename();
    if (file_name.has_filename())
    {
        return file_name.filename().generic_string();
    }

    return std::nullopt;
}

/// @brief 작업 디렉토리를 설정합니다.
void Path::SetWorkingDirectory() noexcept
{
    std::filesystem::current_path(std::filesystem::current_path());
}