#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);
void printArr(vector<int> &arr);

int main() {
	vector<int> arr {12, 11, -13, 5, 6, 7, 6, 5, 1, -5, 19, 4, 9};
	//vector<int> arr {3,4,2,1,5,0,8};
	cout << "Array before sorting: " << endl;
	printArr(arr);
	quick_sort(arr, 0, arr.size()-1);	
	//partition(arr, 0, arr.size()-1);	
	cout << "Array after sorting: " << endl;
	printArr(arr);
	
	return 0;	
}

// partition is the index where the element has been put into its correct position
// now need to sort the left and right sub-array
void quick_sort(vector<int> &arr, int low, int high) {
	if(low >= high)
		return;
	else {		
		int partition_index = partition(arr, low, high);
		cout << "Partition index: " << partition_index << endl;
		quick_sort(arr, low, partition_index-1);
		quick_sort(arr, partition_index+1, high);
	}
	
}

// takes the last element of the array as pivot elelment
// put the pivot element in the correct spot
// makes sure that all the elements in the left of pivot is less than or equal to it
// and all the elements in the right are greater than or equal it
int partition(vector<int> &arr, int low, int high) {
	cout  << "(low, high): " << low << "," << high << endl;
	int pivot = arr[high];
	int left_index=low, right_index=high-1;
	 do{
		while((arr[left_index] < pivot) && (left_index <= right_index)) left_index++;
		while((arr[right_index] > pivot) && (right_index >= left_index)) right_index--;
		if(left_index<right_index)swap(arr[left_index], arr[right_index]);		
	}while(left_index < right_index);
	swap(arr[left_index], arr[high]);
	return left_index;
}

void printArr(vector<int> &arr) {
	for(int i=0; i<arr.size(); i++) {cout << arr[i] << " ";}
	cout << endl; 	
}


