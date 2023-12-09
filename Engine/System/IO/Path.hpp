#ifndef ENGINE_SYSTEM_IO_PATH_HPP
#define ENGINE_SYSTEM_IO_PATH_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#include <filesystem>
#include <fstream>
#include <vector>
#include "../Optional.hpp"
#include "../StringUtils.hpp"

/// @brief Path 클래스
class Path final
{
public:
    static void ChangeExtension(std::string& path, std::string_view extension) noexcept;
    static void ChangeFileName(std::string& path, std::string_view fileName) noexcept;
    static Optional<std::string> Combine(const std::vector<std::string>& paths) noexcept;
    static bool Exists(std::string_view path) noexcept;
    static Optional<std::string> GetDirectoryName(std::string_view path) noexcept;
    static Optional<std::string> GetExtension(std::string_view path) noexcept;
    static Optional<std::string> GetFileName(std::string_view path) noexcept;
    static Optional<std::string> GetFileNameWithoutExtension(std::string_view path) noexcept;
    static void SetWorkingDirectory() noexcept;
};

#endif