#include <iostream>

using namespace std;

int binary_search(int arr[], int n, int len)
{
	static int l = 0, h = len - 1;

	if(l > h)
		return -1;

	int m = l + (h - l) / 2;

	if(arr[m] == n)
		return m;
	else if(arr[m] > n)
		h = m - 1;	
	else
		l = m + 1;

	return binary_search(arr, n, len);
}

int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	cout << binary_search(arr, 2, 5) << endl;

	return 0;
}