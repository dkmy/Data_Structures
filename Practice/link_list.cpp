#include <iostream>
#include <cstdlib>
#include "link_list.h"

using namespace std;


List::List(){
	head = NULL;
	current = NULL;
	temp = NULL;
}

void List::addNode(int newData){
	nodePtr n = new node;
	n -> next = NULL;
	n -> data = newData;
	
	if (head != NULL){ // if not first member
		current = head;
		while (current -> next != NULL){
			current = current -> next;
		}
		current -> next = n;
	}
	else{ // if new then don't matter
		head = n;
	}
}




int main(int argc, char *argv[]) {
	
}