#include <iostream>

using namespace std;

vector <size_t> shuffle(size_t n){
	vector<size_t> a(n);
	a[0] = 0;
	for (size_t i = 1; i < n; ++i){
		size_t j = rand() % (i+1);
		a[i] = a[j];
		a[j] = i;
	}
	return a;
}

/*

3 2 1 4 5

*/

int main(int argc, char *argv[]) {
	
}