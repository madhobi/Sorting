#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int low, int high);
void merge(vector<int> &arr, int low, int middle, int high);
void printArr(vector<int> &arr);

int main() {
	vector<int> arr {12, 11, -13, 5, 6, 7, 6, 5, 1, -5, 19};
	
	cout << "Array before sorting: " << endl;
	printArr(arr);
	mergeSort(arr, 0, arr.size()-1);	
	cout << "Array after sorting: " << endl;
	printArr(arr);
	
	return 0;
}

//divides array into two parts in the middle
//and then call merge() function
void mergeSort(vector<int> &arr, int low, int high) {
	if(low<high) {
		int mid = (low+high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}	
}

//merges two sorted arrays
//one array is arr[low .. middle] and another is arr[middle+1 .. high]
void merge(vector<int> &arr, int low, int middle, int high) {
	int i=low;
	int j=middle+1;
	int k=0;
	vector<int> temp(high-low+1);
	while(i<=middle && j<=high) {
		if(arr[i] < arr[j]) {
			temp[k++] = arr[i++];			
		} else {
			temp[k++] = arr[j++];			
		}
	}
	while(i<=middle) {temp[k++] = arr[i++];}
	while(j<=high) {temp[k++] = arr[j++];}
	for(i=low,k=0; i<=high; i++) {
		arr[i] = temp[k++];
	}	
}

void printArr(vector<int> &arr) {
	for(int i=0; i<arr.size(); i++) {cout << arr[i] << " ";}
	cout << endl; 	
}
