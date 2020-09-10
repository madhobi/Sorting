#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr);
void printArr(vector<int> &arr);

int main() {
		vector<int> arr {12, 11, -13, 5, 6, 7, 6, 5, 1, -5, 19};
		cout << "Array before sorting: " << endl;
		printArr(arr);
		bubble_sort(arr);	
		cout << "Array after sorting: " << endl;
		printArr(arr);
		
		return 0;	
}

void bubble_sort(vector<int> &arr) {
	int i,j;
	for(i=0; i<arr.size(); i++) {
		for(j=i+1; j<arr.size(); j++) {
			if(arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}	
}

void printArr(vector<int> &arr) {
	for(int i=0; i<arr.size(); i++) {cout << arr[i] << " ";}
	cout << endl; 	
}
