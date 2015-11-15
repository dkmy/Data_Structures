#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template<class T>

struct Link {
	 explicit Link(const T& info, Link *next = 0) : info(info), next(next) { }
	// This avoids stack overflow
	~Link() {
		Link *p = next;
		while (p) {
			Link *q = p->next;
			p->next = 0;
			delete p;
			p = q;
		}
	}

	T info;
	Link *next;
};

//vector<int> loopTail(Link* head);
//vector<int> josephus(int n, int k);



vector<int> josephus(int n, int k){
	vector<int> output;
	
	int tempVar = n;

	Link<int>* p = new Link<int>(1);
	Link<int> *temp = p;
	Link<int> *curr = p;
	for (int i = 1; i < n; i++){
		(*temp).next = new Link<int>(i+1);
		temp = (*temp).next;
	}
	(*temp).next = p;
	temp = (*temp).next;

	while (tempVar > 0){
		for (int i = 0; i < k-1; i++){
			temp = curr;
			curr = curr -> next;
		}
//		cout << (*curr).info << "\n";
		output.push_back((*curr).info);
		curr = curr -> next; 
		temp -> next = curr;
		tempVar = tempVar - 1;
	}
	return output;
}

int main(){
	vector<int> a = josephus(10, 3);
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << "\n";
	}
}


