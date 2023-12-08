#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr6.1REC/Pr6.1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestFillArray)
        {
            int arr[arraySize] = { 0 };
            fillArray(arr, 0);
            for (int i = 0; i < arraySize; i++) {
                Assert::IsTrue(arr[i] >= -20 && arr[i] <= 50);
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            int arr[arraySize] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, -5, -10, -15, -20, -25, -30, -35, -40, -45 };
            int count = 0, sum = 0;
            processArray(arr, count, sum, 0);
            Assert::AreEqual(0, count);
            Assert::AreEqual(0, sum);
            for (int i = 10; i < arraySize; i++) {
                if (!(arr[i] > 0 || arr[i] % 5 == 0)) {
                    Assert::AreEqual(0, arr[i]);
                }
            }
        }

    };
}