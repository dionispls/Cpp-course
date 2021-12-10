#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

template < typename T, typename Compare >
void merge(T* arr, const size_t arsiz, const size_t middle, Compare compare)
{
	int left = 0;
	int right = middle;
	T * tmp = new T[arsiz];
	for (auto i = 0U; i < arsiz; ++i){
		if (left < middle
			&& right < arsiz
			&& compare(arr[left], arr[right]))
		{
			tmp[i] = arr[left];
			++left;
		}
		else
            if (left < middle && right < arsiz)
		{
			tmp[i] = arr[right];
			++right;
		}
		else
            if (left < middle)
		{
			tmp[i] = arr[left];
			++left;
		}
		else
		{
			tmp[i] = arr[right];
			++right;
		}
	}
	right = arsiz;
	for (auto i = arsiz; i > 0; --i)
	{
		arr[i - 1] = tmp[i - 1];
	}
	delete[] tmp;
}

template < typename T, typename Compare = less_equal<> >
void merge_sort(T* arr, const size_t arsiz, Compare compare = Compare{})
{
	if (arsiz > 1)
	{
		const size_t middle = arsiz / 2;

		merge_sort(arr, middle, compare);
		merge_sort(arr + middle, arsiz - middle, compare);

		merge(arr, arsiz, middle, compare);
	}
}

template < typename T >
void print(T* arr, const size_t arsiz)
{
	for (auto i = 0U; i < arsiz; ++i)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;
}

template < typename T, size_t N, typename Compare = less_equal<> >
void merge_sort(T(&arr)[N], Compare compare = Compare{})
{
	merge_sort(&arr[0], N, compare);
}

template < typename T, size_t N >
void print(T(&arr)[N])
{
	print(&arr[0], N);
}

