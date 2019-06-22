#include <iostream>
#include <string>
#include <vector>

class MyLib
{
protected:
	// swap two element
	template<class T>
	static inline void _Swap(T &_lhs, T &_rhs)
	{
		T _temp = _lhs;
		_lhs = _rhs;
		_rhs = _temp;
	}

public:
	// compare greater, if _lhs > _rhs return true, if not return false
	template<class T>
	static bool _Greater(T &_lhs, T &_rhs)
	{
		return (_lhs > _rhs);
	}

	// compare less, if _lhs < _rhs return true, if not return false
	template<class T>
	static bool _Less(T &_lhs, T &_rhs)
	{
		return (_lhs < _rhs);
	}

public:
	/**************************************************************************
	**name: bubbleSort
	**func: sorting array using bubble sort
	**input: array _Arr, number element _n
	**		 function pointer bool (*_Compare)(T&, T&), default is _Greater compare
	**output: sorted of array _Arr
	**************************************************************************/
	template<class T>
	static void bubbleSort(T *_Arr, int _n, bool(*_Compare)(T&, T&) = MyLib::_Greater)
	{
		for (int i = 0; i < _n - 1; i++)
		{
			for (int j = 0; j < _n - i - 1; j++)
			{
				if (_Compare(_Arr[j], _Arr[j + 1])) /* compare two element */
				{
					_Swap(_Arr[j], _Arr[j + 1]); /* swap two element */
				}
			}
		}
	}

	/**************************************************************************
	**name: bubbleSort
	**func: sorting list using bubble sort from _First to _Last pointer
	**input: first pointer T *_First, last pointer T *_Last, 
	**		function pointer bool (*_Compare)(T&, T&), default is _Greater compare
	**output: sorted 
	**************************************************************************/
	template<class T>
	static void bubbleSort(T* _First, T* _Last, bool(*_Compare)(T&, T&) = MyLib::_Greater)
	{
		for (T* iIter = _First; iIter != _Last + 1; iIter++)
		{
			for (T* jIter = _First; jIter < _Last - (iIter - _First); jIter++)
			{
				if (_Compare(*jIter, *(jIter + 1))) /* compare two element */
				{
					_Swap(*jIter, *(jIter + 1)); /* swap two element */
				}
			}
		}
	}

protected:
	/**************************************************************************
	**name: partition
	**func: find pivot index for quick sort array
	**input: first element index _Low, last element index _High,
	**		 function pointer bool (*_Compare)(T&, T&), default is _Greater compare
	**output: index of partition
	**************************************************************************/
	template<class T>
	static int partition(T *_Arr, int _Low, int _High, bool(*_Compare)(T&, T&) = MyLib::_Greater)
	{
		int pivot = _Arr[_High]; /* choose pivot is _High*/
		int i = _Low - 1;
		for (int j = _Low; j <= _High - 1; j++)
		{
			if (_Compare(pivot, _Arr[j])) /* compare two element */
			{
				i++;
				_Swap(_Arr[i], _Arr[j]); /* swap two element */
			}
		}
		_Swap(_Arr[i + 1], _Arr[_High]); /* swap with pivot */
		return i + 1;
	}

public:
	/**************************************************************************
	**name: quickSort
	**func: sorting array using quick sort from _Low to _High
	**input: array _Arr, index from _Low to _High
	**		 function pointer bool (*_Compare)(T&, T&), default is _Greater compare
	**output: sorted of array _Arr
	**************************************************************************/
	template<class T>
	static void quickSort(T *_Arr, int _Low, int _High, bool(*_Compare)(T&, T&) = MyLib::_Greater)
	{
		if (_Low < _High)
		{
			int pi = partition(_Arr, _Low, _High, _Compare); /* find pivot index position */
			quickSort(_Arr, _Low, pi - 1, _Compare); /* sort before pi*/
			quickSort(_Arr, pi + 1, _High, _Compare); /* sort after pi*/
		}
	}

protected:
	/**************************************************************************
	**name: partition
	**func: find pivot pointer for quick sort list pointer
	**input: first element _First, last element _Last,
	**		 function pointer bool (*_Compare)(T&, T&), default is _Greater compare
	**output: partition of pointer
	**************************************************************************/
	template<class T>
	static T* partition(T* _First, T* _Last, bool(*_Compare)(T&, T&) = MyLib::_Greater)
	{
		T pivot = *_Last;
		T *iIter = _First - 1;
		for (T *jIter = _First; jIter <= _Last - 1; jIter++)
		{
			if (_Compare(pivot, *jIter)) /* compare two elememt */
			{																																																														
				iIter++;  
				_Swap(*iIter, *jIter); /* swap two element */
			}
		}
		_Swap(*(iIter + 1), *_Last); /* swap with pivot */
		return iIter + 1;
	}

public:
	/**************************************************************************
	**name: quickSort
	**func: sorting using quick sort
	**input: first element _First, last element _Last,
	**		 function pointer bool (*_Compare)(T&, T&), default is _Greater compare
	**output: sorted
	**************************************************************************/
	template<class T>
	static void quickSort(T* _First, T* _Last, bool(*_Compare)(T&, T&) = MyLib::_Greater)
	{
		if (_First < _Last)
		{
			T *pi = partition(_First, _Last, _Compare); /* find pivot pointer position*/
			quickSort(_First, pi - 1, _Compare); /* sort before pi*/
			quickSort(pi + 1, _Last, _Compare); /* sort after pi*/
		}
	}
};

//main function
int main()
{
	/* demo sort using bubble sort */
	int arr[]{ 3, 4, 2, 5, 1 };
	MyLib::bubbleSort(&arr[0], &arr[4], MyLib::_Less);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	/* demo sort using quick sort */
	std::vector<std::string> vec { "bsx", "asd", "fdf", "hfd", "aaa" };
	MyLib::quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}