#ifndef ENGINE_SYSTEM_BASESINGLETON_HPP
#define ENGINE_SYSTEM_BASESINGLETON_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

/// @brief 싱글톤 클래스
/// @tparam T 데이터 형식
/// @note 하나의 인스턴스만을 가지게 하고 싶을 때 사용합니다.
/// @note 싱글톤이 사용된 클래스의 인스턴스는 프로그램 종료 시 제거됩니다.
/// @note 그러므로... 무분별한 싱글톤 사용은 안 됩니다.
template <typename T>
class BaseSingleton 
{
private:

protected:
    BaseSingleton() noexcept            = default;
    virtual ~BaseSingleton() noexcept   = default;

public:
    /// @brief 인스턴스를 취득합니다.
    /// @return 인스턴스
    static T& GetInstance() noexcept 
    {
        static T instance;
        return instance;
    }

    BaseSingleton(const BaseSingleton&) noexcept            = delete;
    BaseSingleton(BaseSingleton&&) noexcept                 = delete;

    BaseSingleton& operator=(const BaseSingleton&) noexcept = delete;
    BaseSingleton& operator=(BaseSingleton&&) noexcept      = delete;
};

#endif