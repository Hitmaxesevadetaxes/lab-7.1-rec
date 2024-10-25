#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Функція для створення матриці
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);  // Випадкові числа в діапазоні [Low, High]
        }
    }
}

// Функція для виведення матриці
void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];  // Виведення елементів з відступами
        }
        cout << endl;
    }
    cout << endl;
}

// Функція для обчислення суми і кількості елементів за критерієм
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;  // Сума елементів
    k = 0;  // Кількість елементів
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] > 0 && j % 2 == 1) {  // Критерій: елемент додатний, а індекс стовпця непарний
                S += a[i][j];
                k++;
                a[i][j] = 0;  // Заміняємо такі елементи на нулі
            }
        }
    }
}

// Функція для перестановки рядків
void ChangeRows(int** a, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

// Функція для сортування рядків матриці
void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++) {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
            if ((a[i1][0] > a[i1 + 1][0]) ||  // За першим стовпчиком
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1]) ||  // Якщо перші елементи рівні, порівнюємо другі
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2])) {  // За третім стовпчиком
                ChangeRows(a, i1, i1 + 1, colCount);  // Перестановка рядків
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    const int rowCount = 7;  // Кількість рядків
    const int colCount = 9;  // Кількість стовпців
    const int Low = -41;  // Нижня межа значень
    const int High = 23;  // Верхня межа значень

    // Створення динамічного масиву (матриці)
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    // 1. Створення матриці
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    // 2. Обчислення кількості та суми елементів, що відповідають критерію, та їх заміна на нулі
    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "Sum of elements: " << S << endl;
    cout << "Number of elements: " << k << endl;

    // Виведення матриці після заміни
    cout << "Matrix after Calc function:" << endl;
    Print(a, rowCount, colCount);

    // 3. Сортування матриці за заданими правилами
    Sort(a, rowCount, colCount);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
