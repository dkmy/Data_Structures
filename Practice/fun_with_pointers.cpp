#include <iostream>

using namespace std;

string_len(const char*p){
	const char *q = p;
	while (*q){
		++q;
	}
	return q-p;
}


int main(int argc, char *argv[]) {
	
}