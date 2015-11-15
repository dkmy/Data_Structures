#include <iostream>
using namespace std;

template<class T>

struct Link {
	Link(const T& info, Link* next){
		this -> info = info;
		this -> next = next;
	}
	~Link(){
		delete next;
	}
	public:
		T info;
		Link* next;
};

//struct add_x {
//	add_x(int x) : x(x) {}
//	int operator()(int y) const { return x + y; }
//	int operator*(int y) const { return x * y;}
//	void change(int k)  {
//		x = k;
//	}
//
//private:
//	int x;
//};

int main(int argc, char *argv[]) {
//	vector<int> output;
	int n = 100;
	int tempVar = n;

	Link<int>* p = new Link<int>(1);
	Link<int> *temp = p;
	Link<int> *curr = p;
	for (int i = 1; i < n; i++){
		(*temp).next = new Link<int>(i+1);
		temp = (*temp).next;
	}
	Link<int> *q = NULL;
	Link<int> *r = p;
	while (p){
		r = r -> next;
		p -> next = q;
		q = p;
		p = r;
	}
	cout << "hi"<<"\n";
	cout << (q->next->next->next->next->next) -> info << "\n";
		

	
}