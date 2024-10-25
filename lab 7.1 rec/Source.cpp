#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// ������� ��� ��������� �������
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);  // �������� ����� � ������� [Low, High]
        }
    }
}

// ������� ��� ��������� �������
void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];  // ��������� �������� � ���������
        }
        cout << endl;
    }
    cout << endl;
}

// ������� ��� ���������� ���� � ������� �������� �� �������
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;  // ���� ��������
    k = 0;  // ʳ������ ��������
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] > 0 && j % 2 == 1) {  // �������: ������� ��������, � ������ ������� ��������
                S += a[i][j];
                k++;
                a[i][j] = 0;  // �������� ��� �������� �� ���
            }
        }
    }
}

// ������� ��� ������������ �����
void ChangeRows(int** a, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        int tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

// ������� ��� ���������� ����� �������
void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++) {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
            if ((a[i1][0] > a[i1 + 1][0]) ||  // �� ������ ����������
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1]) ||  // ���� ����� �������� ���, ��������� ����
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2])) {  // �� ����� ����������
                ChangeRows(a, i1, i1 + 1, colCount);  // ������������ �����
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    const int rowCount = 7;  // ʳ������ �����
    const int colCount = 9;  // ʳ������ ��������
    const int Low = -41;  // ����� ���� �������
    const int High = 23;  // ������ ���� �������

    // ��������� ���������� ������ (�������)
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    // 1. ��������� �������
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    // 2. ���������� ������� �� ���� ��������, �� ���������� �������, �� �� ����� �� ���
    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "Sum of elements: " << S << endl;
    cout << "Number of elements: " << k << endl;

    // ��������� ������� ���� �����
    cout << "Matrix after Calc function:" << endl;
    Print(a, rowCount, colCount);

    // 3. ���������� ������� �� �������� ���������
    Sort(a, rowCount, colCount);

    // ��������� ����������� �������
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    // �������� ���'��
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
