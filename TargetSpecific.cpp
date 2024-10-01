#include "TargetSpecific.h"
#include "CPUID.h"

namespace DB
{

    uint32_t getSupportedArchs()
    {
        uint32_t result = 0;
        if (CPU::CPUFlagsCache::have_SSE42)
            result |= static_cast<uint32_t>(TargetArch::SSE42);
        if (CPU::CPUFlagsCache::have_AVX)
            result |= static_cast<uint32_t>(TargetArch::AVX);
        if (CPU::CPUFlagsCache::have_AVX2)
            result |= static_cast<uint32_t>(TargetArch::AVX2);
        if (CPU::CPUFlagsCache::have_AVX512F)
            result |= static_cast<uint32_t>(TargetArch::AVX512F);
        if (CPU::CPUFlagsCache::have_AVX512BW)
            result |= static_cast<uint32_t>(TargetArch::AVX512BW);
        if (CPU::CPUFlagsCache::have_AVX512VBMI)
            result |= static_cast<uint32_t>(TargetArch::AVX512VBMI);
        if (CPU::CPUFlagsCache::have_AVX512VBMI2)
            result |= static_cast<uint32_t>(TargetArch::AVX512VBMI2);
        if (CPU::CPUFlagsCache::have_AMXBF16)
            result |= static_cast<uint32_t>(TargetArch::AMXBF16);
        if (CPU::CPUFlagsCache::have_AMXTILE)
            result |= static_cast<uint32_t>(TargetArch::AMXTILE);
        if (CPU::CPUFlagsCache::have_AMXINT8)
            result |= static_cast<uint32_t>(TargetArch::AMXINT8);
        return result;
    }

    bool isArchSupported(TargetArch arch)
    {
        static uint32_t arches = getSupportedArchs();
        return arch == TargetArch::Default || (arches & static_cast<uint32_t>(arch));
    }

    std::string toString(TargetArch arch)
    {
        switch (arch)
        {
        case TargetArch::Default:
            return "default";
        case TargetArch::SSE42:
            return "sse42";
        case TargetArch::AVX:
            return "avx";
        case TargetArch::AVX2:
            return "avx2";
        case TargetArch::AVX512F:
            return "avx512f";
        case TargetArch::AVX512BW:
            return "avx512bw";
        case TargetArch::AVX512VBMI:
            return "avx512vbmi";
        case TargetArch::AVX512VBMI2:
            return "avx512vbmi2";
        case TargetArch::AMXBF16:
            return "amxbf16";
        case TargetArch::AMXTILE:
            return "amxtile";
        case TargetArch::AMXINT8:
            return "amxint8";
        }
        return "default";
    }
}