//David Yang

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//bool flip(){
//	return (rand()%2);
//}

bool flip(unsigned long a, unsigned long b) {
	double fraction = double(a) / double(b);
	while (true){	
		fraction = fraction * 2; 
		if (fraction > 1){ //bit is 1, or true in the tree
			if (flip()){
				return true;
			}
			fraction = fraction -1;
		} 
		else{ //bit is 0, or false in the tree
			if (!flip()){
				return false;
			}
		}
	}
	return false;
}

bool bad_flip(){
	return flip(1, 5);
}

bool good_flip(){ //(T+F)^2 - T^2 - F^2 = TF + FT, TF = FT. 
	bool a, b;
	while (true){
		a = bad_flip();
		b = bad_flip();
		if (a == b){
			continue;
		}
		return a;
	}
	return false;
}

/*
Expected number of function calls to bad_flip() is :
1/(2p - 2p^2)

Let (a) be the probability of getting the same flip (TT or FF) twice in a row.
(a) = p^2 + (1-p)^2 
Therefore, 1 - (a) is the probability of not doing (a), and no more need to call bad_flip() once you succeed.
You can express the expected number of calls, S, as

S = (1-a) + 2(1-a)(a) + 3(1-a)(a^2) + 4(1-a)(a^3)......
aS =          (1-a)(a) + 2(1-a)(a^2) + 3(1-a)(a^3)...
S - aS = (1-a)(1 + a + a^2 + ....)
S = 1 + a + a^2 + a^3 + ....
aS =    a + a^2 + a^3 + ....
S - aS = 1
S = 1/(1-a)
S = 1/(1 - (2p^2 - 2p + 1) = 1/(2p - 2p^2)
*/


int main(){
//	srand (time(0));
//	int a = 0;
//	for (int i=0; i<10000; i++){
//		a = a + flip(1, 3);
////		a = a + good_flip();
//	}
//	cout << a/10000.0;
//	return 0;
	cout << "Hello World!" << "\n";
	return 0;
}