#include <iostream>


//quicksort used to divide and conquer
//Use the coffee method, partition
using namespace std;

int qs1partition(int a[], int lo, int hi){
	int x = a[lo];
	while (lo <= hi){
		while (a[lo] < x) ++ lo;
		while (a[hi] > x) --hi;
		if (lo <= hi){
			int t = a[lo];
			a[lo++] = a[hi];
			a[hi--] = t;
		}
		
	}
	return lo;
}

void further_partitioning(int a[], int address, int lo, int hi){
	int m = qs1partition(a, lo, hi);
	if (m < address){
		further_partitioning(int a[], address, m, hi){
	}
	else{
		address = address - lo;
		further_partitioning(int a[], address, m, hi);
	}
	return;
}


int main() {
	cout << "hello World" << "\n";
	return 0;
}