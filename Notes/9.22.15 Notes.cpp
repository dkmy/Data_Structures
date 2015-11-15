//9.22.15 notes

Do josephus thing 

Floyds algorithm

Say you have a linked list with something pointing to a previous node, aka loop

The algoirthm uses the following concept: Have a fast and a slow pointer, and if loop exists, fast pointer and slow pointer will meet.

1) is it corrupted: tortopise & Hare 

2) Walk around loop and determine length. When they meet, keep the fast one on hold, and the slow one will go around and count. 

3) Determine Length of tail: Start from the beginning, proceed by length of loop, and proceed doing +1 until they meet. Try drawing it ull figure it out 

What can we do with linked lists?? STACKS 

Abstract Data Type (ADT) {}
----------------
Specify behavior, not implementation 

0) Construct an empty sack
1) Can add an element
2) Can remove the most recently added element //lIFO
3) Can ask if it is empty


template <class T>

class Stack{
	public:
		Stack(); //construct
		Stack(const Stack& s);
		Stack& operator=(const Stack& s);
		~Stack(){}; //destructors
		void push(const T& x);
		
		T pop(); T top() const; //pop returns void so u don't knwo wth was in that 
		bool is_empty() const;
		
	private:
		vector<T> a; //hold the elements
		size_t n;
};

bool Stack<T>::is_empty() const{
	return n ==0;
}

void push(const T& x){
	if (a.size() == n){
		a.push_back(x); //expand the size of vector
		++n;
	}
	else{
		a[n++] = x; //jsut fill it in. no need to expand vector size. We want to put x in nth position and then incremenet, not the other order
	}
}

T pop() {
	if (!n){
		throw Stack_Empty_Exception();
	}
	return a[--n]; //if there's n elements, must decremenet 
}

Stack() : a(), n(0) {}


What can we do with stacks? 

//S(n)/n! approaches 0
//permutation possibel made by stacks is miniscule fraction. You can prove this. Pssible permutation is configuration of (push, pop) to certain extent 

//get S(n) as a function








