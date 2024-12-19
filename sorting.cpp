#include<iostream>
#include<string>
using namespace std;
void selection_sort(int arr[],int n)
{
	int minIndex;
	
	for(int i=0;i<n-1;i++)
	{
		minIndex = i;
		for(int j=i+1;j<n;j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}

}
void bubble_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool swapped = false;

		for(int j = 0; j < n - 1 - i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}
void insertion_sort(int arr[], int n)
{
	int keyNum, pre;

	for(int i=1;i<n;i++)
	{
		keyNum=arr[i];
		pre = i - 1;
		while(pre >=0 && arr[pre]>keyNum)
		{
			arr[pre + 1] = arr[pre];
			pre--;
		}
		arr[pre + 1] = keyNum;
	}
}
// Helper function to print arrays
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Test function
void test_sorting_function(void(*sortFunc)(int[], int), const string& funcName) {
	int testCase = 1;

	// Test case 1: General case
	int arr1[] = { 20, 1, -4, 2, 5 };
	sortFunc(arr1, 5);
	cout << "Test case " << testCase++ << " (" << funcName << "): ";
	printArray(arr1, 5);

	// Test case 2: Already sorted array
	int arr2[] = { 1, 2, 3, 4, 5 };
	sortFunc(arr2, 5);
	cout << "Test case " << testCase++ << " (" << funcName << "): ";
	printArray(arr2, 5);

	// Test case 3: Reverse order
	int arr3[] = { 5, 4, 3, 2, 1 };
	sortFunc(arr3, 5);
	cout << "Test case " << testCase++ << " (" << funcName << "): ";
	printArray(arr3, 5);

	// Test case 4: Single element
	int arr4[] = { 42 };
	sortFunc(arr4, 1);
	cout << "Test case " << testCase++ << " (" << funcName << "): ";
	printArray(arr4, 1);


	// Test case 5: Duplicates
	int arr5[] = { 1, 2, 2, 3, 1 };
	sortFunc(arr5, 5);
	cout << "Test case " << testCase++ << " (" << funcName << "): ";
	printArray(arr5, 5);
}

int main() {
	cout << "Testing selection_sort:" << endl;
	test_sorting_function(selection_sort, "selection_sort");

	cout << "\nTesting bubble_sort:" << endl;
	test_sorting_function(bubble_sort, "bubble_sort");

	cout << "\nTesting insertion_sort:" << endl;
	test_sorting_function(insertion_sort, "insertion_sort");

	return 0;
}