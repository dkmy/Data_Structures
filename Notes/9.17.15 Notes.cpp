#include <iostream>

using namespace std;

//Notes from 9/17/15


//typedef int vector<int> ::value_type;

template <class C>
sum(typename C::const_iterator beg, typename C::const_iterator end){
	typedef typename C::value_type VAL;
	typedef typename C::const_interator CIT;
	//Typename tells the compiler that the content of the typename is a type, like int or something
	VAL s = VAL();
	
	for (CIT p = beg; p != end;){
		s += *p++;
	}	
	
	return s;
}


int main(int argc, char *argv[]) {
	double a[] = {1,3,7};
//	vector<short> b;
	
	double s = sum(a, a+3); //you can use arrays like this cuz wh not
	
	cout << s;
}


#include <iostream>
#include <iomanip> //the heck is this??


//suppose you want to do the following

const double pi = acos(-1);
cout << pi; //3.141593, but how do we control number of decimal places

cout << cout::set_precision(15) << pi; //syntax looks something like this

//Okay, how does this work. Here's an example of what it might look like
class BjarnesCoolClass {
};

//There's some overloading of the ostream of << that spits out precision

for (int i = 0; i<u; ++i){
	a[i] += b[i] * t;
}


 

