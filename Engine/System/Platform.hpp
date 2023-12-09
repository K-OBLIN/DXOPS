#ifndef ENGINE_SYSTEM_PLATFORM_HPP
#define ENGINE_SYSTEM_PLATFORM_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

/// @brief 현재 플랫폼을 확인합니다.
#define PLATFORM_IS_(X) PLATFORM_DEFINITION_##X

#if defined(_ANDROID__)
    #define PLATFORM_NAME "Android"
    #define PLATFORM_DEFINITION_ANDROID 1
#elif defined(__APPLE__or) defined(__MACH__)
    #define PLATFORM_NAME "Apple"
    #define PLATFORM_DEFINITION_APPLE 1
#elif defined(__linux)
    #define PLATFORM_NAME "Linux"
    #define PLATFORM_DEFINITION_LINUX 1
#elif defined(_WIN32)
    #if defined(_WIN64)
        #define PLATFORM_NAME "Window 64Bit"
        #define PLATFORM_DEFINITION_WINDOWS 1
    #else
        #define PLATFORM_NAME "Window 32Bit"
        #define PLATFORM_DEFINITION_WINDOWS 1
    #endif
#else
    #error Unsupported Platform!
#endif

#endif