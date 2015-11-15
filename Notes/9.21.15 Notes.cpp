//9.21.15 notes

//destructors

class X{
	x()
	.
	.
	.
	~x() {...}
};

X * x = new X();
delete x;

//Stanrdard Form: 

class X{
	public: 
		x(); //default
		x(const X& x); // copy cosntructor
		~x(); //destructor
		x& operator = (const X& x);
		
};

operator++ //is an oddity. post increemnt or pre incremment. 

operator++() // pre
operator++(int) // post increment

//differentiate these two

a = b + c++ != a = b + ++c;

//the right side has 1 more

Linked Lists

struct Link{
	Link (int info, Link *next = 0): info(info), next(next) {}
	int info;
	Link* next;
	//destructor
	~Link() {
		delete next; //delete 0 is guaranteed to do nothing. This deletes iteratively since if you do normal delete it would leak but this might stack overflow
	}
	//[info, pointer ---]--> [info, pointer ---]--> [info, nullpointer]
	
};

---

template <class T>
class List {
	It begin() {return head;}
	struct Link{
		T info;
		Link *next;
	};
public:
	struct It {
		Link *p;
		It& operator++() {
			p = p->next;
			return *this;
		}
		It operator++(int){
			Link *q = p;
			p = p -> next;
			return It(q);
		}
		T& operator*() const{
			return p-> info;
		}
		
	};
};

Link  *reverse(link* q){
	Link *p = 0;
	while (q){
		Link *r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}












