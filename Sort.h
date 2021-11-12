// ----------------------------------------------------------------------------------
// ������� ������ �������� ����������

template<class type>
void Swap(type& x, type& y)
{
	type temp = x;
	x = y;
	y = temp;
}
// ---------------------------------------------
// ���������� ������� (������)
template<class type>
void BubbleSort(type* a, long n)
{
	for (long i = 0; i < n - 1; i++)
		for (long j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) Swap(a[j], a[j - 1]);
}
	// -----------------------------------------
	// ���������� ���������
	template<class type>
	void InsertSort(type* a, long n)
	{
		for (long i = 1; i < n; i++)
		{
			type x = a[i];
			long j = i - 1;
			for (; j >= 0 && a[j] > x; j--) a[j + 1] = a[j];
			a[j + 1] = x;
		}
	}

