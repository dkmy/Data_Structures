#include <iostream>

using namespace std;

template <class T>
struct Link{
	Link(const T& t, Link* point = 0){
		info = t;
		next = point;
	}
	Link(const Link& z);
	
	~Link(){
		if (next){
			delete next;
		}
	}
	
	public:
		T info;
		Link* next;
	
};

/*
0) Construct an empty sack
1) Can add an element
2) Can remove the most recently added element //lIFO
3) Can query if it is empty
*/


struct Stack{
	Stack(Link<int>* head = 0, Link<int>* tail =0){
		this -> head = head;
		this -> tail = tail;
	}
	
	void pop(){
//		cout << "HEY" << "\n";
		Link<int>* temp = head;
		cout << head->info << "\n";
		temp = temp -> next;
		head -> next = NULL;
		head = temp;
	}
	
	void push(Link<int>* something){
		something->next = head; 
		head = something; 
	}
	
	private:
		Link<int>* head;
		Link<int>* tail;
};
int main(int argc, char *argv[]) {
	Link<int>* p = new Link<int>(1);
	Link<int>* temp;
		for (int i = 0; i < 1000; i++){
			int n;
			int Loop;
			n=100;
			
			int tempVar = n;
			
			
			
			Link<int> *temp = p;
			Link<int> *curr = p;
			Link<int>* link = p;
			for (int i = 1; i < n; i++){
				
				(*temp).next = new Link<int>(i+1);
				temp = (*temp).next;
			}
		}
//	cout << (p->info) << "\n";
	Stack a(p, temp);
	a.push(p);
	cout << Stack;
	
			
}