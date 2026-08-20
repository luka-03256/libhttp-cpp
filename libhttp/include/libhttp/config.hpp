/**
*
* @author: Luka Stefanovic
* @date: Aug-20, 2026
* @description: { 	}
* @brief:
*/

#define LIBHTTP_PLATFORM_WINDOWS      0
#define LIBHTTP_PLATFORM_LINUX        0
#define LIBHTTP_PLATFORM_MACOS        0
#define LIBHTTP_PLATFORM_FREEBSD      0
#define LIBHTTP_PLATFORM_UNKNOWN      0

// -----------------------------------------------------------------------------
// Platform detection
// -----------------------------------------------------------------------------
#pragma once

/*Platform detection */
#if defined (_WIN32) || defined(_WIN64)
  #undef LIBHTTP_PLATFORM_WINDOWS
	#define LIBHTTP_PLATFORM_WINDOWS 1
#elif defined (__APPLE__) && defined(__MACH__)
  #undef LIBHTTP_PLATFORM_MACOS
	#define LIBHTTP_PLATFORM_MACOS 1
#elif defined(__linux__)
  #undef LIBHTTP_PLATFORM_LINUX
	#define LIBHTTP_PLATFORM_LINUX 1
#elif defined(__FreeBSD__)
  #undef LIBHTTP_PLATFORM_FREEBSD
	#define LIBHTTP_PLATFORM_FREEBSD 1
#else
  #undef LIBHTTP_PLATFORM_UNKNOWN
	#define LIBHTTP_PLATFORM_UNKNOWN 1
#endif


// -----------------------------------------------------------------------------
// Compiler detection
// -----------------------------------------------------------------------------
#if defined (_MSC_VER)
	#define LIBHTTP_COMPILER_MSVC 1
#elif defined(__clang__)
	#define LIBHTTP_COMPILER_CLANG 1
#elif defined(__GNUC__)
	#define LIBHTTP_COMPILER_GCC 1
#endif


// -----------------------------------------------------------------------------
// Shared library visibility
// -----------------------------------------------------------------------------

#if defined(_WIN32) || defined(_WIN64)
    #if defined(LIBHTTP_BUILD_SHARED)
        #if defined(LIBHTTP_EXPORTS)
            #define LIBHTTP_API __declspec(dllexport)
        #else
            #define LIBHTTP_API __declspec(dllimport)
        #endif
    #else
        #define LIBHTTP_API
    #endif

#elif defined(__GNUC__) || defined(__clang__)
    #if defined(LIBHTTP_BUILD_SHARED)
        #define LIBHTTP_API __attribute__((visibility("default")))
    #else
        #define LIBHTTP_API
    #endif
#else
    #define LIBHTTP_API
#endif
