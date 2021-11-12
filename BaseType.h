// Заголовочный файл BaseType.h, прмиеняемый при разработке
// программы исследования алгоритмов сортировки
// ------------------------------------------------------------

#ifndef BASE_TYPE_H
#define BASE_TYPE_H
#include <cstdlib> // для функции rand()
// ------------------------------------------------------------
unsigned long CmpCount; // Счетчик сравнений
unsigned long MovCount; // Счетчик пересылок (присваиваний)
// ------------------------------------------------------------
// Функция обнуления счетчиков
void ClearCoutn()
{
	CmpCount = 0; MovCount = 0;
}
// Функция, возвращающая количество сделанных сравнений
unsigned long GetCmpCount()
{
	return CmpCount;
}
// Функция возвращающая количество сделанных пересылок
unsigned long GetMovCount()
{
	return MovCount;
}
// Функция возвращающая суммарное количество
// сделанных сравнений и пересылок
unsigned long GetAllCount()
{
	return CmpCount + MovCount;
}
// -------------------------------------------------------------
// Определение типов данных:
// Key - int
typedef int Key;
// Data - int
typedef int Data;
// BaseType - тип элемента массива подверженного сортировке
// по полю Key
struct BaseType
{
	Key key; // Ключевое поле
	Data data; // Поле данных

// Переопределение оператора присваивания 
	BaseType& operator= (const BaseType& Var)
	{
		key = Var.key;
		data = Var.data; MovCount++; return *this;
	}
	// Переопределение оператора сравнения на меньше
	bool operator< (const BaseType& Var) const
	{
		CmpCount++;
		return(key < Var.key);
	}
	// Переопределение оператора сравнения на меньше или равно
	bool operator<= (const BaseType& Var) const
	{
		CmpCount++;
		return(key <= Var.key);
	}
	// Переопределение оператора на больше
	bool operator > (const BaseType& Var) const
	{
		CmpCount++;
		return(key > Var.key);
	}
	// Переопределение оператора сравнения на больше или равно
	bool operator>= (const BaseType& Var)const
	{
		CmpCount++;
		return(key >= Var.key);
	}
	// Переопределение оператора сравнения равенство
	bool operator== (const BaseType& Var) const
	{
		CmpCount++;
		return(key == Var.key);
	}
	// Переопределение оператора сравнения на неравенство
	bool operator!= (const BaseType& Var) const
	{
		CmpCount++;
		return(key != Var.key);
	}
};


void RandArray(BaseType* a, long n)
{
	for (long i = 0; i < n; i++)
	{
		a[i].key = rand() % 1000;
		a[i].data = i;
	}
}
//------------------------------------------------------------------------
// Функция формирования массива упорядоченного по возрастанию
void SortArray(BaseType* a, long n)
{
	for (long i = 0; i < n; i++)
	{
		a[i].key = i;
		a[i].data = i;
	}
}
//-------------------------------------------------------------------------\
// Функция формирования массива упорядоченного по убыванию
void UnSortArray(BaseType* a, long n)
{
	for (long i = 0; i < n; i++)
	{
		a[i].key = n - i;
		a[i].data = i;
	}
}
#endif // BASE_TYPE_H


