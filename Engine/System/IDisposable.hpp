#ifndef ENGINE_SYSTEM_IDISPOSABLE_HPP
#define ENGINE_SYSTEM_IDISPOSABLE_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

/// @brief 자원 정리 인터페이스
class IDisposable
{
public:
    virtual ~IDisposable() noexcept = default;
    virtual void Dispose() noexcept = 0;
};

#endif