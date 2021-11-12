// PR1_Grigorev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> // Функция потокового ввода/вывода
using namespace std;
#include <conio.h>
// Заголовочный файл, содержащий определение функций сортировки
#include "Sort.h"
#include "BaseType.h" // Заголовочный файл представленный выше
// Количество различных разномерностей сортируемого массива
#define N 4
// --------------------------------------------------------------------------
int main(int args, char* argv[])
{
    setlocale(LC_ALL, ""); // Подключение Кириллицы
    // Количество элементов в массиве
    int SizeArray[N] = { 10,20,50,100 };
    // Массив указателей на случайные массивы
    BaseType* ProbArray[N];
    // Цикл по разной разномерности
    // Для формирования массивов случайным образом
    for (int i = 0; i < N; i++)
    {
        ProbArray[i] = new BaseType[SizeArray[i]];
        RandArray(ProbArray[i], SizeArray[i]);
    }
    BaseType* a; // Указатель на сортируемый массив
    // Эксперименты с алгоритмом сортировки обменом
    cout << "BubbleSort: " << endl;
    // Цикл по разной размерности массива
    for (int i = 0; i < N; i++)
    {
        a = new BaseType[SizeArray[i]];
            // Исследование среднего случая (случайный массив)
        for (int j = 0; j < SizeArray[i]; j++) a[j] = ProbArray[i][j];
            cout << "Средний случай:" << endl;
            ClearCoutn();
            BubbleSort(a, SizeArray[i]);
            cout << "Для случайного массива long " << SizeArray[i]
                << "общее количество операций " << GetAllCount() << endl;
            _getch();
            // Исследование лучшего случая (упорядоченный массив)
            SortArray(a, SizeArray[i]);
            cout << "Лучший случай: " << endl;
            ClearCoutn();
            BubbleSort(a, SizeArray[i]);
            cout << "Для упорядоченного массива long " << SizeArray[i]
                << "общеее количество операций " << GetAllCount() << endl;
            _getch();
            // Исследование худшего случая
            // (массив, упорядоченный в обратном порядке)
            UnSortArray(a, SizeArray[i]);
            cout << "Худший случай: " << endl;
            ClearCoutn();
            BubbleSort(a, SizeArray[i]);
            cout << "Для массива, заказанного в порядке возврата long"
                << SizeArray[i]
                << "общее количество операций " << GetAllCount() << endl;
            _getch();
            delete a;
    }
    // Эксперименты с алгоритмом сортировки вставками
    cout << "InsertSort: " << endl;
    // Цикл по разной размерности массива
    for (int i = 0; i < N; i++)
    {
        a = new BaseType[SizeArray[i]];
        // Исследование среднего слуая 9случайный массив) 
        for (int j = 0; j < SizeArray[i]; j++) a[j] = ProbArray[i][j];
        cout << "Средний случай: " << endl;
        ClearCoutn();
        InsertSort(a, SizeArray[i]);
        cout << "Для случайного массива long " << SizeArray[i]
            << "общее количество операций " << GetAllCount() << endl;
        _getch();
        // Исследование лучшего случая (упорядоченный массив)
        SortArray(a, SizeArray[i]);
        cout << "Лучший случай: " << endl;
        ClearCoutn();
        InsertSort(a, SizeArray[i]);
        cout << "Для упорядоченного массива long " << SizeArray[i]
            << "общее количество операций: " << GetAllCount() << endl;
        _getch();
        // Исследование худшего случая
        // массив упорядоченный в обратном порядке)
        UnSortArray(a, SizeArray[i]);
        cout << "Худший случай: " << endl;
        ClearCoutn();
        InsertSort(a, SizeArray[i]);
        cout << "Для массива, заказанного в порядке возврата long "
            << SizeArray[i]
            << "общее количество операций: " << GetAllCount() << endl;
        _getch();
        delete a;
    }
    for (int i = 0; i < N; i++) delete ProbArray[i];
    return 0;
}


