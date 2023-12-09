#ifndef ENGINE_SYSTEM_MEMORY_HPP
#define ENGINE_SYSTEM_MEMORY_HPP

#if defined(_MSC_VER)
    #pragma once
#endif

#if defined(_DEBUG)
    #define _CRTDBG_MAP_ALLOC
    #include <crtdbg.h>
    #include <cstdlib>
#endif

#include <memory>

#endif