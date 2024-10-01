#pragma once
#include <string>
#include <cstdint>

namespace DB
{

enum class TargetArch : uint32_t
{
    Default  = 0,
    SSE42    = (1 << 0),
    AVX      = (1 << 1),
    AVX2     = (1 << 2),
    AVX512F  = (1 << 3),
    AVX512BW    = (1 << 4),
    AVX512VBMI  = (1 << 5),
    AVX512VBMI2 = (1 << 6),
    AMXBF16 = (1 << 7),
    AMXTILE = (1 << 8),
    AMXINT8 = (1 << 9),
};

/// Runtime detection.
bool isArchSupported(TargetArch arch);

std::string toString(TargetArch arch);

#ifndef ENABLE_MULTITARGET_CODE
#   define ENABLE_MULTITARGET_CODE 0
#endif

#if ENABLE_MULTITARGET_CODE && defined(__GNUC__) && defined(__x86_64__)

#define USE_MULTITARGET_CODE 1

#define AVX512VBMI2_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f,avx512bw,avx512vl,avx512vbmi,avx512vbmi2")))
#define AVX512VBMI_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f,avx512bw,avx512vl,avx512vbmi")))
#define AVX512BW_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f,avx512bw")))
#define AVX512_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f")))
#define AVX2_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,bmi2")))
#define AVX_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt,avx")))
#define SSE42_FUNCTION_SPECIFIC_ATTRIBUTE __attribute__((target("sse,sse2,sse3,ssse3,sse4,popcnt")))
#define DEFAULT_FUNCTION_SPECIFIC_ATTRIBUTE

#   define BEGIN_AVX512VBMI2_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f,avx512bw,avx512vl,avx512vbmi,avx512vbmi2\"))),apply_to=function)")
#   define BEGIN_AVX512VBMI_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f,avx512bw,avx512vl,avx512vbmi\"))),apply_to=function)")
#   define BEGIN_AVX512BW_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f,avx512bw\"))),apply_to=function)")
#   define BEGIN_AVX512F_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,avx512f\"))),apply_to=function)")
#   define BEGIN_AVX2_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,bmi2\"))),apply_to=function)")
#   define BEGIN_AVX_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt,avx\"))),apply_to=function)")
#   define BEGIN_SSE42_SPECIFIC_CODE \
        _Pragma("clang attribute push(__attribute__((target(\"sse,sse2,sse3,ssse3,sse4,popcnt\"))),apply_to=function)")
#   define END_TARGET_SPECIFIC_CODE \
        _Pragma("clang attribute pop")

/* Clang shows warning when there aren't any objects to apply pragma.
 * To prevent this warning we define this function inside every macros with pragmas.
 */
#   define DUMMY_FUNCTION_DEFINITION [[maybe_unused]] void _dummy_function_definition();


#define DECLARE_SSE42_SPECIFIC_CODE(...) \
BEGIN_SSE42_SPECIFIC_CODE \
namespace TargetSpecific::SSE42 { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::SSE42; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE

#define DECLARE_AVX_SPECIFIC_CODE(...) \
BEGIN_AVX_SPECIFIC_CODE \
namespace TargetSpecific::AVX { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::AVX; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE

#define DECLARE_AVX2_SPECIFIC_CODE(...) \
BEGIN_AVX2_SPECIFIC_CODE \
namespace TargetSpecific::AVX2 { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::AVX2; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE

#define DECLARE_AVX512F_SPECIFIC_CODE(...) \
BEGIN_AVX512F_SPECIFIC_CODE \
namespace TargetSpecific::AVX512F { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::AVX512F; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE

#define DECLARE_AVX512BW_SPECIFIC_CODE(...) \
BEGIN_AVX512BW_SPECIFIC_CODE \
namespace TargetSpecific::AVX512BW { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::AVX512BW; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE

#define DECLARE_AVX512VBMI_SPECIFIC_CODE(...) \
BEGIN_AVX512VBMI_SPECIFIC_CODE \
namespace TargetSpecific::AVX512VBMI { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::AVX512VBMI; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE

#define DECLARE_AVX512VBMI2_SPECIFIC_CODE(...) \
BEGIN_AVX512VBMI2_SPECIFIC_CODE \
namespace TargetSpecific::AVX512VBMI2 { \
    DUMMY_FUNCTION_DEFINITION \
    using namespace DB::TargetSpecific::AVX512VBMI2; \
    __VA_ARGS__ \
} \
END_TARGET_SPECIFIC_CODE


#else

#define USE_MULTITARGET_CODE 0

/* Multitarget code is disabled, just delete target-specific code.
 */
#define DECLARE_SSE42_SPECIFIC_CODE(...)
#define DECLARE_AVX_SPECIFIC_CODE(...)
#define DECLARE_AVX2_SPECIFIC_CODE(...)
#define DECLARE_AVX512F_SPECIFIC_CODE(...)
#define DECLARE_AVX512BW_SPECIFIC_CODE(...)
#define DECLARE_AVX512VBMI_SPECIFIC_CODE(...)
#define DECLARE_AVX512VBMI2_SPECIFIC_CODE(...)

#endif

#define DECLARE_DEFAULT_CODE(...) \
namespace TargetSpecific::Default { \
    using namespace DB::TargetSpecific::Default; \
    __VA_ARGS__ \
}

#define DECLARE_MULTITARGET_CODE(...) \
DECLARE_DEFAULT_CODE         (__VA_ARGS__) \
DECLARE_SSE42_SPECIFIC_CODE  (__VA_ARGS__) \
DECLARE_AVX_SPECIFIC_CODE    (__VA_ARGS__) \
DECLARE_AVX2_SPECIFIC_CODE   (__VA_ARGS__) \
DECLARE_AVX512F_SPECIFIC_CODE(__VA_ARGS__) \
DECLARE_AVX512BW_SPECIFIC_CODE    (__VA_ARGS__) \
DECLARE_AVX512VBMI_SPECIFIC_CODE  (__VA_ARGS__) \
DECLARE_AVX512VBMI2_SPECIFIC_CODE (__VA_ARGS__)

DECLARE_DEFAULT_CODE(
    constexpr auto BuildArch = TargetArch::Default;
) // DECLARE_DEFAULT_CODE

DECLARE_SSE42_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::SSE42;
) // DECLARE_SSE42_SPECIFIC_CODE

DECLARE_AVX_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::AVX;
) // DECLARE_AVX_SPECIFIC_CODE

DECLARE_AVX2_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::AVX2;
) // DECLARE_AVX2_SPECIFIC_CODE

DECLARE_AVX512F_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::AVX512F;
) // DECLARE_AVX512F_SPECIFIC_CODE

DECLARE_AVX512BW_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::AVX512BW;
) // DECLARE_AVX512BW_SPECIFIC_CODE

DECLARE_AVX512VBMI_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::AVX512VBMI;
) // DECLARE_AVX512VBMI_SPECIFIC_CODE

DECLARE_AVX512VBMI2_SPECIFIC_CODE(
    constexpr auto BuildArch = TargetArch::AVX512VBMI2;
) // DECLARE_AVX512VBMI2_SPECIFIC_CODE


/// Function header
#define MULTITARGET_FUNCTION_HEADER(...) __VA_ARGS__

/// Function body
#define MULTITARGET_FUNCTION_BODY(...) __VA_ARGS__

#if ENABLE_MULTITARGET_CODE && defined(__GNUC__) && defined(__x86_64__)

#define MULTITARGET_FUNCTION_AVX2_SSE42(FUNCTION_HEADER, name, FUNCTION_BODY) \
    FUNCTION_HEADER \
    \
    AVX2_FUNCTION_SPECIFIC_ATTRIBUTE \
    name##AVX2 \
    FUNCTION_BODY \
    \
    FUNCTION_HEADER \
    \
    SSE42_FUNCTION_SPECIFIC_ATTRIBUTE \
    name##SSE42 \
    FUNCTION_BODY \
    \
    FUNCTION_HEADER \
    \
    name \
    FUNCTION_BODY \

#define MULTITARGET_FUNCTION_AVX512BW_AVX512F_AVX2_SSE42(FUNCTION_HEADER, name, FUNCTION_BODY) \
    FUNCTION_HEADER \
    \
    AVX512BW_FUNCTION_SPECIFIC_ATTRIBUTE \
    name##AVX512BW \
    FUNCTION_BODY \
    \
    FUNCTION_HEADER \
    \
    AVX512_FUNCTION_SPECIFIC_ATTRIBUTE \
    name##AVX512F \
    FUNCTION_BODY \
    \
    FUNCTION_HEADER \
    \
    AVX2_FUNCTION_SPECIFIC_ATTRIBUTE \
    name##AVX2 \
    FUNCTION_BODY \
    \
    FUNCTION_HEADER \
    \
    SSE42_FUNCTION_SPECIFIC_ATTRIBUTE \
    name##SSE42 \
    FUNCTION_BODY \
    \
    FUNCTION_HEADER \
    \
    name \
    FUNCTION_BODY \

#else


#define MULTITARGET_FUNCTION_AVX2_SSE42(FUNCTION_HEADER, name, FUNCTION_BODY) \
    FUNCTION_HEADER \
    \
    name \
    FUNCTION_BODY \


#define MULTITARGET_FUNCTION_AVX512BW_AVX512F_AVX2_SSE42(FUNCTION_HEADER, name, FUNCTION_BODY) \
    FUNCTION_HEADER \
    \
    name \
    FUNCTION_BODY \

#endif

}