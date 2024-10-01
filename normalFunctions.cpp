#include "TargetSpecific.h"
#include <iostream>

#if USE_MULTITARGET_CODE
#include <immintrin.h>
#endif

DECLARE_DEFAULT_CODE(
    void funcImpl(int *a, int *b, int *result, int size) {
        for (int i = 0; i < size; ++i)
        {
            result[i] = a[i] + b[i];
        }
        std::cout << toString(BuildArch) << std::endl;
    }) // DECLARE_DEFAULT_CODE

DECLARE_SSE42_SPECIFIC_CODE(
    void funcImpl(int *a, int *b, int *result, int size) {
        for (int i = 0; i < size; ++i)
        {
            result[i] = a[i] + b[i];
        }
        std::cout << toString(BuildArch) << std::endl;
    }) // DECLARE_SSE42_SPECIFIC_CODE

DECLARE_AVX2_SPECIFIC_CODE(
    void funcImpl(int *a, int *b, int *result, int size) {
        for (int i = 0; i < size; ++i)
        {
            result[i] = a[i] + b[i];
        }
        std::cout << toString(BuildArch) << std::endl;
    }) // DECLARE_AVX2_SPECIFIC_CODE

int main()
{
    int size = 32;
    int a[size] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
    int b[size] = {8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1};
    int result[size] = {0};

#if USE_MULTITARGET_CODE
    if (isArchSupported(DB::TargetArch::SSE42))
    {
        TargetSpecific::SSE42::funcImpl(a, b, result, size);
    }
    else if (isArchSupported(DB::TargetArch::AVX2))
    {
        TargetSpecific::AVX2::funcImpl(a, b, result, size);
    }
#else
    TargetSpecific::Default::funcImpl(a, b, result, size);
#endif

    std::cout << "Result: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}