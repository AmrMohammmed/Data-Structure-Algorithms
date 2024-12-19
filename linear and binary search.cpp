#include<iostream>
using namespace std;

int linear_search(int arr[], int arrSize, int item)
{

	for(int i=0;i<arrSize;i++)
	{
		if (item == arr[i])
			return i;
	}
	return -1;
}

int binary_search(int arr[],int arrSize, int item)
{

	int left = 0;
	int right = arrSize - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (item == arr[mid])
			return mid;

		else if (item > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}


int main()
{
	
	int arr[] = {1,3,5,7,9,12,14,15};// Array should be sorted for binary search
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	int searchItem;
	cout << "Enter Number : ";
	cin >> searchItem;

	int linear_result = linear_search(arr, arrSize, searchItem);
	int binary_result = binary_search(arr, arrSize, searchItem);


	if (linear_result == -1)
		cout << searchItem << " not found with linear search" << endl;
	else
		cout << searchItem << " at index : "<<linear_result << "\t  using linear search"<< endl;


	if (binary_result == -1)
		cout << searchItem << " not found with binary search" << endl;
	else
		cout << searchItem << " at index : " << binary_result<<"\t  using binary search"<< endl;


	return 0;
}