#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>

using namespace std;
using namespace chrono;


//calculating running time function of n^2 algorithms.
void calculateRunningTimeOfSelectionSort(void (*function)(vector<int>, int), vector<int> list, int size);
void calculateRunningTimeOfInsertionSort(void (*function)(vector<int>, int), vector<int> list, int size);
void calculateRunningTimeOfBubbleSort(void (*function)(vector<int>, int), vector<int> list, int size);

//calculating running time function of n logn algorithms.
void calculateRunningTimeOfMergeSort(void (*function)(vector<int>, int, int, int), vector<int> list, int size, int start, int end);

void calculateRunningTimeOfQuickSort(void (*function)(vector<int>, int, int, int), vector<int> list, int size, int start, int end);

//swap function
void swap(int* a, int* b);

//O(n^2) sorting algorithms
void selectionSort(vector<int> list, int size);
void bubbleSort(vector<int> list, int size);
void insertionSort(vector<int> list, int size);

//O(n logn) algorithms
void mergeSort(vector<int> list, int size, int start, int end);
void mergeArr(vector<int> list, int size, int start, int mid, int end);
void quickSort(vector<int> list, int size, int start, int end);

int main(void)
{
	int sizeOfInput;

	cout << "Enter size: ";
	cin >> sizeOfInput;

	//recording the size input unto the text file:
	ofstream outfile("SizeOfInput.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << sizeOfInput << "," << endl;
        outfile.close();
    }
    else
    	cerr << "Error!" << endl; 

	srand(time(NULL));

	vector<int> listOfNums(1);
	for(int i=0; i<sizeOfInput; i++)
	{
		int randNum = (rand() % 10) + 1;
		listOfNums.push_back(randNum);
	}

	selectionSort(listOfNums, sizeOfInput);
	calculateRunningTimeOfSelectionSort(selectionSort, listOfNums, sizeOfInput);

	insertionSort(listOfNums, sizeOfInput);
	calculateRunningTimeOfInsertionSort(insertionSort, listOfNums, sizeOfInput);

	bubbleSort(listOfNums, sizeOfInput);
	calculateRunningTimeOfBubbleSort(bubbleSort, listOfNums, sizeOfInput);

	mergeSort(listOfNums, sizeOfInput, 0, sizeOfInput);
	calculateRunningTimeOfMergeSort(mergeSort, listOfNums, sizeOfInput, 0, sizeOfInput);

	quickSort(listOfNums, sizeOfInput, 0, sizeOfInput-1);
	calculateRunningTimeOfQuickSort(quickSort, listOfNums, sizeOfInput, 0, sizeOfInput);

	return 0;
}

//swap function implementation.
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	//free(temp);
}

//O(n^2) sorting algo.
void selectionSort(vector<int> list, int size)
{
	int small, idx_small;

	for(int i=0; i<size; i++)
	{
		idx_small = i;
		for(int j=i+1; j<size; j++)
		{
			if(list[j] < list[idx_small])
			{
				idx_small = j;
			}
		}
		swap(list[i], list[idx_small]);	
	}
	// for(int index=0; index<size; index++)
	// 	cout << list[index] <<", ";
	// cout << endl;
}

//O(n^2) sorting algo.
void bubbleSort(vector<int> list, int size)
{
	int i = 0;
	bool exchange = 1;
	while(exchange)
	{
		exchange = 0;
		for(int j=size-1; j>i; j--)
		{
			if(list[j] < list[j-1])
			{
				swap(list[j], list[j-1]);
				exchange = 1;
			}
		}
		// for(int index=0; index<size; index++)
		// 	cout << list[index] << ", ";
		// cout << endl;
		i++;
	}
}

//O(n^2) sorting algo.
void insertionSort(vector<int> list, int size)
{
	int key, j;
	for(int i=0; i<size; i++)
	{
		key = list[i];
		j = i-1;

		while(key < list[j] && j >= 0)
		{
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = key;

		// for(int index=0; index<size; index++)
		// 	cout << list[index] << ", ";
		// cout << endl;
	}
}

//O(n logn) sorting algo.
void mergeSort(vector<int> list, int size, int start, int end)
{
	//to be implemented.
	int mid;
	if(start < end)
	{
		mid = (start + end) / 2;

		mergeSort(list, size, start, mid);

		mergeSort(list, size, mid+1, end);
		
		mergeArr(list, size, start, mid, end);
	}
}

//O(n logn) sorting algo.
void mergeArr(vector<int> list, int size, int start, int mid, int end)
{
	//to be implemented.
	int temp[size], size2, ptr1, ptr2;
	int i, j;

	size2 = end - start;
	ptr1 = start;
	ptr2 = mid + 1;

	j = 0;

	while(ptr1 < mid+1 && ptr2 < end + 1)
	{
		if(list[ptr1] < list[ptr2])
		{
			temp[j] = list[ptr1];
			ptr1++;
			j++;
		} else {
			temp[j] = list[ptr2];
			ptr2++;
			j++;
		}
	}
	if(ptr1 < mid+1)
	{
		for(i = j; i<size2+1; i++)
		{
			temp[i] = list[ptr1];
			ptr1++;
		}
	}

	if(ptr2 < end + 1)
	{
		for(i = j; i<size2 + 1; i++)
		{
			temp[i] = list[ptr2];
			ptr2++;
		}
	}
	for(j = 0; j<size2+1; j++)
		list[start + j] = temp[j];
}

//O(n logn) sorting algo.
void quickSort(vector<int> list, int size, int start, int end)
{
	//to be implemented.
	int i, j, pivot;
	if(start < end)
	{
		pivot = list[start];
		i = start + 1;
		while(list[i] < pivot)
			i++;
		j = end;
		while(list[j] > pivot)
			j--;
		while(i < j)
		{
			swap(list[i], list[j]);
			i++;
			while(list[i] < pivot)
				i++;
			j--;
			while(list[j] > pivot)
				j--;
		}
		swap(list[start], list[j]);
		// for(int index = 0; index < size; index++)
		// 	cout << list[index] << ",";
		// cout << endl;
	}
}

void calculateRunningTimeOfSelectionSort(void (*function)(vector<int>, int), vector<int> list, int size) 
{
	auto start = high_resolution_clock::now();  

	function(list, size);  

	auto stop = high_resolution_clock::now();  
	auto duration = duration_cast<seconds>(stop - start);

	cout << "Time taken by Selection Sort: " << duration.count() << " seconds" << endl;

	ofstream outfile("SelectionSort.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << duration.count() << "," << endl;
        outfile.close();
    }
    else
    	cerr << "Error!" << endl; 
}

void calculateRunningTimeOfInsertionSort(void (*function)(vector<int>, int), vector<int> list, int size) 
{
	auto start = high_resolution_clock::now();  

	function(list, size);  

	auto stop = high_resolution_clock::now();  
	auto duration = duration_cast<seconds>(stop - start);

	cout << "Time taken by Insertion Sort: " << duration.count() << " seconds" << endl;

	ofstream outfile("Insertion.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << duration.count() << "," << endl;
        outfile.close();
    }
    else
    	cerr << "Error!" << endl; 
}

void calculateRunningTimeOfBubbleSort(void (*function)(vector<int>, int), vector<int> list, int size) 
{
	auto start = high_resolution_clock::now();  

	function(list, size);  

	auto stop = high_resolution_clock::now();  
	auto duration = duration_cast<seconds>(stop - start);

	cout << "Time taken by Bubble Sort: " << duration.count() << " seconds" << endl;

	ofstream outfile("BubbleSort.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << duration.count() << "," << endl;
        outfile.close();
    }
    else
    	cerr << "Error!" << endl; 
}

void calculateRunningTimeOfMergeSort(void (*function)(vector<int>, int, int, int), vector<int> list, int size, int start, int end)
{
	auto startTime = high_resolution_clock::now();  

	function(list, size, start, end);  

	auto stop = high_resolution_clock::now();  
	auto duration = duration_cast<seconds>(stop - startTime);

	cout << "Time taken by Merge Sort: " << duration.count() << " seconds" << endl;

	ofstream outfile("MergeSort.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << duration.count() << "," << endl;
        outfile.close();
    }
    else
    	cerr << "Error!" << endl; 
}

void calculateRunningTimeOfQuickSort(void (*function)(vector<int>, int, int, int), vector<int> list, int size, int start, int end)
{
	auto startTime = high_resolution_clock::now();  

	function(list, size, start, end);  

	auto stop = high_resolution_clock::now();  
	auto duration = duration_cast<seconds>(stop - startTime);

	cout << "Time taken by Quick Sort: " << duration.count() << " seconds" << endl;

	ofstream outfile("QuickSort.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << duration.count() << "," << endl;
        outfile.close();
    }
    else
    	cerr << "Error!" << endl; 
}