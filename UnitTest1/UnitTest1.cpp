
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 7.1 rec\lab 7.1 rec\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** testMatrix = new int* [rowCount];
            testMatrix[0] = new int[colCount] { 1, 2, -3 };
            testMatrix[1] = new int[colCount] { 4, 5, 6 };
            testMatrix[2] = new int[colCount] { -7, 8, 9 };

            int sum = 0;
            int count = 0;

            // Act: Викликаємо функцію Calc
            Calc(testMatrix, rowCount, colCount, sum, count);

            // Assert: Перевіряємо результат
            // Сума елементів на непарних стовпцях: 2 + 5 + 8 = 15
            Assert::AreEqual(15, sum);
            // Кількість елементів, що відповідають критерію (непарні стовпці > 0): 3
            Assert::AreEqual(3, count);
            Assert::AreEqual(0, testMatrix[0][1]);
            Assert::AreEqual(0, testMatrix[1][1]);
            Assert::AreEqual(0, testMatrix[2][1]);


            for (int i = 0; i < rowCount; i++) {
                delete[] testMatrix[i];
            }
            delete[] testMatrix;
        };
    };
};