// ������������ ���� BaseType.h, ����������� ��� ����������
// ��������� ������������ ���������� ����������
// ------------------------------------------------------------

#ifndef BASE_TYPE_H
#define BASE_TYPE_H
#include <cstdlib> // ��� ������� rand()
// ------------------------------------------------------------
unsigned long CmpCount; // ������� ���������
unsigned long MovCount; // ������� ��������� (������������)
// ------------------------------------------------------------
// ������� ��������� ���������
void ClearCoutn()
{
	CmpCount = 0; MovCount = 0;
}
// �������, ������������ ���������� ��������� ���������
unsigned long GetCmpCount()
{
	return CmpCount;
}
// ������� ������������ ���������� ��������� ���������
unsigned long GetMovCount()
{
	return MovCount;
}
// ������� ������������ ��������� ����������
// ��������� ��������� � ���������
unsigned long GetAllCount()
{
	return CmpCount + MovCount;
}
// -------------------------------------------------------------
// ����������� ����� ������:
// Key - int
typedef int Key;
// Data - int
typedef int Data;
// BaseType - ��� �������� ������� ������������� ����������
// �� ���� Key
struct BaseType
{
	Key key; // �������� ����
	Data data; // ���� ������

// ��������������� ��������� ������������ 
	BaseType& operator= (const BaseType& Var)
	{
		key = Var.key;
		data = Var.data; MovCount++; return *this;
	}
	// ��������������� ��������� ��������� �� ������
	bool operator< (const BaseType& Var) const
	{
		CmpCount++;
		return(key < Var.key);
	}
	// ��������������� ��������� ��������� �� ������ ��� �����
	bool operator<= (const BaseType& Var) const
	{
		CmpCount++;
		return(key <= Var.key);
	}
	// ��������������� ��������� �� ������
	bool operator > (const BaseType& Var) const
	{
		CmpCount++;
		return(key > Var.key);
	}
	// ��������������� ��������� ��������� �� ������ ��� �����
	bool operator>= (const BaseType& Var)const
	{
		CmpCount++;
		return(key >= Var.key);
	}
	// ��������������� ��������� ��������� ���������
	bool operator== (const BaseType& Var) const
	{
		CmpCount++;
		return(key == Var.key);
	}
	// ��������������� ��������� ��������� �� �����������
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
// ������� ������������ ������� �������������� �� �����������
void SortArray(BaseType* a, long n)
{
	for (long i = 0; i < n; i++)
	{
		a[i].key = i;
		a[i].data = i;
	}
}
//-------------------------------------------------------------------------\
// ������� ������������ ������� �������������� �� ��������
void UnSortArray(BaseType* a, long n)
{
	for (long i = 0; i < n; i++)
	{
		a[i].key = n - i;
		a[i].data = i;
	}
}
#endif // BASE_TYPE_H


