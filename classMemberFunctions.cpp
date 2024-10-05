#include "TargetSpecific.h"
#include <iostream>

#if USE_MULTITARGET_CODE
#include <immintrin.h>
#endif

class TestClass
{
public:
    MULTITARGET_FUNCTION_AVX512BW_AVX512F_AVX2_SSE42(
        MULTITARGET_FUNCTION_HEADER(void), testFunctionImpl, MULTITARGET_FUNCTION_BODY((int *a, int *b, int *result, int size) {
            for (int i = 0; i < size; ++i)
            {
                result[i] = a[i] + b[i];
            }
        }))

    void testFunction(int *a, int *b, int *result, int size)
    {
#if USE_MULTITARGET_CODE
        if (isArchSupported(DB::TargetArch::AVX512BW))
        {
            std::cout << DB::toString(DB::TargetArch::AVX512BW) << std::endl;
            testFunctionImplAVX512BW(a, b, result, size);
        }
        else if (isArchSupported(DB::TargetArch::AVX512F))
        {
            std::cout << DB::toString(DB::TargetArch::AVX512F) << std::endl;
            testFunctionImplAVX512F(a, b, result, size);
        }
        else if (isArchSupported(DB::TargetArch::AVX2))
        {
            std::cout << DB::toString(DB::TargetArch::AVX2) << std::endl;
            testFunctionImplAVX2(a, b, result, size);
        }
        else if (isArchSupported(DB::TargetArch::SSE42))
        {
            std::cout << DB::toString(DB::TargetArch::SSE42) << std::endl;
            testFunctionImplSSE42(a, b, result, size);
        }
        else
        {
            std::cout << DB::toString(DB::TargetArch::Default) << std::endl;
            testFunctionImpl(a, b, result, size);
        }
#else
        std::cout << DB::toString(DB::TargetArch::Default) << std::endl;
        testFunctionImpl(a, b, result, size);
#endif
    }
};

int main()
{
    int size = 32;
    int a[32] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
    int b[32] = {8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1};
    int result[32] = {0};

    TestClass test;
    test.testFunction(a, b, result, size);

    std::cout << "Result: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}