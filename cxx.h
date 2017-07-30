#ifdef CXX
#error "CXX macros already defined"
#endif

//------------------------------------------------------------------------------

#define CXX CXX_NAME ", " CXX_OS_NAME " " CXX_CPU_NAME " (" CXX_ENDIAN_NAME ")"

//------------------------------------------------------------------------------

#ifndef CXX_DEBUG
    #if defined(DEBUG) || defined(_DEBUG)
        #define CXX_DEBUG 1
    #elif defined(__GNUC__) && !defined(__OPTIMIZE)
        #define CXX_DEBUG 1
    #endif
#endif

//------------------------------------------------------------------------------
// CXX_CONCAT(x,y)
//
// Concatenate the macro-expanded results of arguments x and y.
//
#define  CXX_CONCAT(x,y) _CXX_CONCAT(x,y)
#define _CXX_CONCAT(x,y) x##y

//------------------------------------------------------------------------------
// CXX_QUOTE(x)
//
// Surround the macro-expanded result of argument x in quotes.
//
#define  CXX_QUOTE(x) _CXX_QUOTE(x)
#define _CXX_QUOTE(x) #x

//------------------------------------------------------------------------------

#if defined(__clang__)

    #define CXX_ID     clang
    #define CXX_CLANG  (__clang_major__*10000+__clang_minor__*100+__clang_patchlevel__)
    #define CXX_NAME   "Clang " __clang_version__

#elif defined(__GNUC__)

    #define CXX_ID    gcc
    #define CXX_GCC   (__GNUC__*10000+__GNUC_MINOR__*100+__GNUC_PATCHLEVEL__)
    #define CXX_NAME  "GCC " __VERSION__

#elif defined(_MSC_VER)

    #define CXX_ID    msvc
    #define CXX_MSVC  (_MSC_VER)
    #define CXX_NAME  "MSVC " CXX_QUOTE(_MSC_FULL_VER)

#else

    #error "unrecognized compiler"

#endif

//------------------------------------------------------------------------------

#if defined(__ANDROID__)

    #define CXX_OS_ANDROID    1
    #define CXX_OS_ID         android
    #define CXX_OS_NAME       "Android"

#elif defined(__linux)

    #define CXX_OS_LINUX      1
    #define CXX_OS_ID         linux
    #define CXX_OS_NAME       "Linux"

#elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)

    #define CXX_OS_APPLE      1
    #define CXX_OS_IOS        1
    #define CXX_OS_ID         ios
    #define CXX_OS_NAME       "iOS"

#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)

    #define CXX_OS_APPLE      1
    #define CXX_OS_MACOS      1
    #define CXX_OS_ID         macos
    #define CXX_OS_NAME       "macOS"

#elif __cplusplus_winrt

    #define CXX_OS_MICROSOFT  1
    #define CXX_OS_WINRT      1
    #define CXX_OS_ID         winrt
    #define CXX_OS_NAME       "WinRT"

#elif defined(_WIN32)

    #define CXX_OS_MICROSOFT  1
    #define CXX_OS_WINDOWS    1
    #define CXX_OS_ID         windows
    #define CXX_OS_NAME       "Windows"

#else

    #error "unsupported platform"

#endif

//------------------------------------------------------------------------------

#if defined(__aarch64__)

    // ARM 64
    #define CXX_CPU_ARM    1
    #define CXX_CPU_ARM_64 1
    #define CXX_CPU_ID     arm_64
    #define CXX_CPU_NAME   "ARM64"
    #define CXX_CPU_BITS   64

#elif \
    defined(ARM)     || \
    defined(_ARM)    || \
    defined(__arm)   || \
    defined(__arm__)

    // ARM 32
    #define CXX_CPU_ARM    1
    #define CXX_CPU_ARM_32 1
    #define CXX_CPU_ID     arm_32
    #define CXX_CPU_NAME   "ARM"
    #define CXX_CPU_BITS   32

#elif \
    defined(__powerpc64__) || \
    defined(__ppc64__)

    // PPC 64
    #define CXX_CPU_PPC    1
    #define CXX_CPU_PPC_64 1
    #define CXX_CPU_ID     ppc_64
    #define CXX_CPU_NAME   "PowerPC 64"
    #define CXX_CPU_BITS   64

#elif \
    defined(__POWERPC__) || \
    defined(__PPC__)     || \
    defined(__powerpc__) || \
    defined(__ppc__)     || \
    defined(_POWER)      || \
    defined(powerpc)

    // PPC 32
    #define CXX_CPU_PPC    1
    #define CXX_CPU_PPC_32 1
    #define CXX_CPU_ID     ppc_32
    #define CXX_CPU_NAME   "PowerPC"
    #define CXX_CPU_BITS   32

#elif \
    defined(_M_X64)     || \
    defined(_M_AMD64)   || \
    defined(__x86_64__)

    // x86-64
    #define CXX_CPU_X86    1
    #define CXX_CPU_X86_64 1
    #define CXX_CPU_ID     x86_64
    #define CXX_CPU_NAME   "x86-64"
    #define CXX_CPU_BITS   64

#elif \
    defined(_M_IX86)  || \
    defined(__386__)  || \
    defined(__i386__) || \
    defined(__X86__)  || \
    defined(i386)

    // x86
    #define CXX_CPU_X86    1
    #define CXX_CPU_X86_32 1
    #define CXX_CPU_ID     x86_32
    #define CXX_CPU_NAME   "x86"
    #define CXX_CPU_BITS   32

#else

    #error "unrecognized CPU architecture"

#endif

//------------------------------------------------------------------------------

#if CXX_CPU_X86 || CXX_CPU_X86_64 || (CXX_CPU_ARM && !__BIG_ENDIAN__)

    #define CXX_ENDIAN_LE     0x01020304u
    #define CXX_ENDIAN_BE     0
    #define CXX_ENDIAN        CXX_ENDIAN_LE
    #define CXX_ENDIAN_NAME   "little endian"

#elif CXX_CPU_PPC

    #define CXX_ENDIAN_LE     0
    #define CXX_ENDIAN_BE     0x04030201u
    #define CXX_ENDIAN        CXX_ENDIAN_BE
    #define CXX_ENDIAN_NAME   "big endian"

#else

    #error "unrecognized endianness"

#endif