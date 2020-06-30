#include <iostream>

using namespace std;

template <typename T>
class array
{
public:
	T* arr;
	int size;
	int capacity;

	array(){}
	array(int _capacity)
	{
		this->size = 0;
		this->capacity = _capacity;
		arr = new T[this->capacity];
	}
	array(array& arr2)
	{
		size = arr2.size;
		capacity = arr2.capacity;
		arr = new T[capacity];
		for (int i = 0; i < size; i++)
			arr[i] = arr2.arr[i];
	}
	~array() 
	{ 
		delete []arr;
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void init()
	{
		size = capacity;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
	void append(T item)
	{
		arr[size++] = item;
	}
	void append(array& arr2)
	{
		if(capacity - size - arr2.size < 0)
		{
			T* arrr = new T[size+arr2.size];
			for (int i = 0; i < size; i++)
				arrr[i] = arr[i];
			delete[] arr;
			arr = arrr;
		}
		for (int i = 0, j = size; i < arr2.size; i++, j++)
			arr[j] = arr2.arr[i];
		size += arr2.size;
	}
	void insert(int index, T item)
	{
		int i = size++;
		while(i > index)
		{
			arr[i] = arr[i-1];
			i--;
		}
		arr[index] = item;
	}
	void insert2(int index, T item)
	{
		for (int i = size++; i > index; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[index] = item;
	}
	void _delete(int index)
	{
		int i = index;
		while(i < size-1)
		{
			arr[i] = arr[i+1];
			i++;
		}
		size--;
	}
	T linier_search(T item)
	{
		for (int i = 0; i < size; i++)
		{
			if(item == arr[i])
			{
				return i;
				/*
				transposition
				swap(arr[i], arr[i-1]);	
				return i - 1;
				*/
				/*
				move to fornt
				swap(arr[i], arr[0]);
				return 0;
				*/
			}
		}
		return -1;
	}
	T get(int index)
	{ 
		if(index >= 0 && index < size)
			return arr[index]; 
		return -1;
	}
	void set(int index, T item)
	{
		arr[index] = item;
	}
	T max()
	{
		T MAX = arr[0];
		for (int i = 1; i < size; i++)
			if(arr[i] > MAX)
				MAX = arr[i];
		return MAX;
	}
	T min()
	{
		T MIN = arr[0];
		for (int i = 1; i < size; i++)
			if(arr[i] < MIN)
				MIN = arr[i];
		return MIN;
	}
	void reverse()
	{
		int i = 0;
		int j = size-1;
		while(i < j)
		{
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	}
	void left_rotate(int index)
	{
		int i = index;
		int j;
		while(i > 0)
		{
			j = i-1;
			T temp = arr[j];
			while(j < size - 1)
			{
				arr[j] = arr[j+1];
				j++;
			}
			i--;
			arr[j] = temp;
		}
	}
	void left_rotate2(int index = 1)
	{
		while(index > 0)
		{
			T temp = arr[0];
			left_shift();
			arr[size-1] = temp;
			index--;
		}

	}
	void right_rotate(int index)
	{
		int i = index;
		int j;
		while(i < size - 1) 
		{
			j = i+1;
			T temp = arr[j];
			while(j > 0)
			{
				arr[j] = arr[j-1];
				j--;
			}
			i++;
			arr[j] = temp;
		}
	}
	void right_rotate2(int index = 1)
	{
		while(index > 0)
		{
			T temp = arr[size-1];
			right_shift();
			arr[0] = temp;
			index--;
		}
	}
	T sum()
	{
		T s = 0;
		for (int i = 0; i < size; i++)
			s += arr[i];
		return s;
	}
	T rsum()
	{
		static int i = 0;
		if(i > size - 1)
			return 0;
		return arr[i++]+rsum();
	}
	double avg()
	{
		T total = sum();
		return total/size;
	}
	void left_shift(int shift = 1)
	{
		while(shift > 0)
		{
			int i = 0;
			while(i < size - 1)
			{
				arr[i] = arr[i+1];
				i++;
			}
			arr[i] = 0;
			shift--;
		}
	}
	void right_shift(int shift = 1, int until = 0)
	{
		while(shift > 0)
		{
			int i = size - 1;
			while(i > until)
			{
				arr[i] = arr[i-1];
				i--;
			}
			arr[i] = 0;
			shift--;
		}
	}
	void sort_insert(T item)
	{
		int i = size-1;
		while(item < arr[i])
		{
			arr[i+1] = arr[i];
			i--;
		}
		arr[++i] = item;
		size++;
	}
	bool isSorted()
	{
		for (int i = 1; i < size; i++)
		{
			if(arr[i-1] > arr[i])
			{
				return false;
			}
		}
		return true;
	}
	void pm_sort()
	{
		int i = 0;
		int j = size-1;
		while(i < j)
		{
			while(arr[i] < 0) i++;
			while(arr[j] >= 0) j--;
			if(i < j)
			{
				i++; 
				j--;
			}
		}
	}
	int compare(array& arr2)
	{
		if(size < arr2.size)
			return -1;
		else if(size > arr2.size)
			return 1;
		return 0;
	}
	void copy(array& arr2)
	{
		for (int i = 0, j = size; i < arr2.size; i++, j++)
			arr[j] = arr2.arr[i];
		size += arr2.size;
	}
	void marge(array arr2)
	{
		T* new_arr = new T[size+arr2.size];
		int i, j, k;
		i=j=k=0;
		while(i < size && j < arr2.size)
		{
			if(arr[i] < arr2.arr[j])
				new_arr[k++] = arr[i++];
			else 
				new_arr[k++] = arr2.arr[j++];
		}
		while(i < size)
			new_arr[k++] = arr[i++];
		while(j < arr2.size)
			new_arr[k++] = arr2.arr[j++];
		delete[] arr;
		arr = new_arr;
		size += arr2.size;
	}
	void _union(array arr2)
	{
		T* arrr = new T[size+arr2.size];
		int i;
		for (i = 0; i < size; i++)
			arrr[i] = arr[i];
		int k = i;
		for (i = 0; i < arr2.size; i++)
			if(linier_search(arr2.arr[i]) == -1)
				arrr[k++] = arr2.arr[i];
		size = k;
		delete[] arr;
		arr = arrr;
	}
	void sort_union(array arr2)
	{
		T* new_arr = new T[size+arr2.size];
		int i, j, k;
		i=j=k=0;
		while(i < size && j < arr2.size)
		{
			if(arr[i] < arr2.arr[j])
				new_arr[k++] = arr[i++];
			else if(arr[i] > arr2.arr[j])
				new_arr[k++] = arr2.arr[j++];
			else
			{
				new_arr[k] = arr[i];
				i++; j++; k++;
			}
		}
		while(i < size)
			new_arr[k++] = arr[i++];
		while(j < arr2.size)
			new_arr[k++] = arr2.arr[j++];
		delete[] arr;
		arr = new_arr;
		size = k;
	}
	void sort_intersection(array arr2)
	{
		T* new_arr = new T[size];
		int i, j, k;
		i=j=k=0;
		while(i < size && j < arr2.size)
		{
			if(arr[i] == arr2.arr[j])
			{
				new_arr[k] = arr[i];
				i++; j++; k++;
			}
			else if(arr[i] < arr2.arr[j]) i++;
			else j++;
		}
		delete[] arr;
		arr = new_arr;
		size = k;
	}
	void intersection(array arr2)
	{
		T* new_arr = new T[size];
		int i = 0, k = 0;
		while(i < size)
		{
			if(arr2.linier_search(arr[i]) > -1)
				new_arr[k++] = arr[i]; 
			i++; 
		}
		delete[] arr;
		arr = new_arr;
		size = k;
	}
	void difference(array arr2)
	{
		T* new_arr = new T[size];
		int i = 0, k = 0;
		while(i < size)
		{
			if(arr2.linier_search(arr[i]) == -1)
				new_arr[k++] = arr[i]; 
			i++; 
		}
		delete[] arr;
		arr = new_arr;
		size = k;
	}
	void sort_difference(array arr2)
	{
		T* new_arr = new T[size];
		int i, j, k;
		i=j=k=0;
		while(i < size && j < arr2.size)
		{
			if(arr[i] < arr2.arr[j])
				new_arr[k++] = arr[i++];
				
			else if(arr[i] > arr2.arr[j]) j++;
			else
			{
				i++;
				j++;
			}
		}
		while(i < size)
			new_arr[k++] = arr[i++];
		delete[] arr;
		arr = new_arr;
		size = k;
	}
};

int main()
{
	array<int> odd(10);
	odd.append(1);
	odd.append(3);
	odd.append(5);
	odd.append(7);
	odd.append(9);
	odd.show();

	array<int> even(5);
	even.append(1);
	even.append(2);
	even.append(3);
	even.append(6);
	even.append(7);
	// even.append(0);
	// even.append(2);
	// even.append(4);
	// even.append(6);
	// even.append(8);

	even.show();

	cout << odd.size << endl;
	odd.sort_difference(even);
	odd.show();
	cout << odd.size << endl;

	return 0;
}