#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>

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
 
vector<int> josephus(int n, int k){ //pretty sure negative is just exited 
	vector<int> output;
	int tempVar = n;
	if (n <= 0){
		cout << "Nobody here?" << "\n";
		exit(-1);
	}
	
	if (n == 1){ //now this is just lazy, but...
		output.push_back(1);
		return output;
	}
	
	if (k <= 0){ //nobody dies! 
		cout << "nessuno muore!" << "\n";
		exit(-1);
	}
	
	Link<int>* p = new Link<int>(1); //make first 
	Link<int> *temp = p;
	Link<int> *curr = p;
	for (int i = 1; i < n; i++){ //make rest 
		(*temp).next = new Link<int>(i+1); 
		temp = (*temp).next;
	}
	(*temp).next = p; //loop back
	temp = (*temp).next;
	
	while (tempVar > 0){
		for (int i = 0; i < k-1; i++){
			temp = curr;
			curr = curr -> next;
		}
		output.push_back((*curr).info);
		curr = curr -> next;  //delete the node 
		temp -> next = curr;
		tempVar = tempVar - 1;
	}
	
	return output;
}

template<class T>
vector<int> loopTail(Link<T>* head){
	vector<int> output;
	int totalSize = 0; //if cycleSize == 0, this is size of list.
	
	if (head == 0){
		output.push_back(0);
		output.push_back(0);
		return output;
	}
	
	int tailSize = 0;
	int cycleSize = 0; 
	bool cycle = false; 
	Link<T>* curr = head;
	Link<T>* fast = head;
	
	
	//process 1
	while (fast){ //check for cycle. while so it's not pointing to null
		fast = fast -> next; //move fast first 
		if (fast == curr){
			cycle = true; 
			break;
		}
		totalSize = totalSize + 1;
		if (fast == curr){
			cycle = true; 
			break;
		}
		if (!fast){ //so fast isn't pointing to a null. If it is, doing next would make the computer unhappy;
			break;
		}		
		fast = fast -> next;		
		totalSize = totalSize + 1;
		curr = curr -> next; //now move current 
		
	}
	
	if (!cycle){ //not a cycle? trivial. Just return totalSize 
		output.push_back(0);
		output.push_back(totalSize);
		return output;
	}
	
	//process 2
	
	while (true){ //it is a cycle :( fix fast and start moving current
		curr = curr -> next;
		cycleSize = cycleSize + 1;
		if (curr == fast){
			output.push_back(cycleSize);
			break;
		}
	}
	
	//process 3
	
	Link<T>* point1 = head; 
	Link<T>* point2 = head;
	
	for (int i = 0; i < cycleSize; i++){ //move point2 the size of cycle
		point2 = point2 -> next;
	}
	
	while (true){ //iterate through and see when they meet
		if (point1 == point2){ 
			output.push_back(tailSize);
			break;
		}
		point1 = point1 -> next;
		point2 = point2 -> next;
		tailSize = tailSize + 1;
	}
	return output;
}

int main(){
	cout << "Everything should work this time..." << endl;
	return 0;
}

//int main(){
//	cout << (josephus(2, 2))[1] << "\n";
//	cout << "Hey" << "\n";
//	ifstream fin("floyd.in");
//	for (int i=0; i<1000; i++){
//		int listSize, loopLink, loopSize, tailSize;
//		fin >> listSize >> loopLink >> loopSize >> tailSize;
//		vector<int> out = loopTail(generate_case(listSize, loopLink));
//		if (out[0] == loopSize && out[1] == tailSize){
//			cout << i << " YES" << "\n";
//		}
//		else{
//			cout << i << " NO" << "\n";
//			cout << loopSize << " " << tailSize << "\n";
//			cout << out[0] << " " << out[1] << "\n";
//		}
//	
//	}
//	return 0;
//}
//int main() {
//	ifstream fin("josephus.in");
//	for (int i=0; i < 100; i++){
//		int n; 
//		int k;
//		fin >> n;
//		fin >> k;
//		
//		vector<int> myOut = josephus(n, k);
//		
//		for (int j = 0; j < myOut.size(); j++){
//			int tempIn;
//			fin >> tempIn;
//			if (myOut[j] != tempIn){
//				cout << "NOPE" << "\n";
//				break;
//			}
////			cout << i << " YES" << "\n";
//		}
//	}
//	return 0;
//}