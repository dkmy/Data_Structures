//
//  tree.cpp
//  Data Structures
//
//  Created by David Kang Myung Yang on 11/13/15.
//  Copyright (c) 2015 David Kang Myung Yang. All rights reserved.
//



//#ifndef ____tree__
//#define ____tree__

#include <iostream>
#include <cassert>
#include "tree.h"
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <ctime>

using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::stack;
using std::cin;
using std::cout;
using std::cerr;


Tree::Entry::Entry(const string& key, double val) : key(key), val(val) {}
Tree::Entry::Entry(const Entry& e) : key(e.key), val(e.val) {}

Tree::Node::Node(const Entry& e, Node *l, Node *r, size_t n) : e(e), l(l), r(r), n(n) {}


Tree::It::It(const It& i) : p(i.p), s(i.s) {}


double& Tree::It::operator*() const{
	return (p->e).val;
}

Tree::It Tree::It::operator++(int){ 
	// Post-increment
//	Tree::It tempNew(Node* k, const stack<Node*>& g);
//	It tempNew(p, s);
	Node *tempNode = p;
	stack<Node*> tempStack = s;
//	tempNew.s = s;
	if (p -> r){
		(tempStack).push(tempNode);
		tempNode = p -> r;
		
		while (tempNode -> l){
			(tempStack).push(tempNode);
			tempNode = tempNode -> l;
		}
		return It(tempNode, tempStack);
	}
	
	Node* tempNode1 = tempStack.top();
	if (tempNode == tempNode1 -> r){
		return It(tempNode, tempStack);
	}
	(tempStack).pop();
	if (tempNode == tempNode1 -> l){
		tempNode = tempNode1 -> l;
		while (true){
			(tempStack).push(tempNode);
			tempNode = tempNode -> l;
		}
		p = tempNode;
		s = tempStack;
		return It(tempNode, tempStack);
	}
	return It(tempNode, tempStack);	
	//account for this being your root
}    

Tree::It& Tree::It::operator++(){ 
	// Post-increment
//	Tree::It tempNew(Node* k, const stack<Node*>& g);
//	It tempNew(p, s);
	Node *tempNode = p;
	stack<Node*> tempStack = s;
//	tempNew.s = s;
	if (p -> r){
		(tempStack).push(tempNode);
		tempNode = p -> r;
		
		while (tempNode -> l){
			(tempStack).push(tempNode);
			tempNode = tempNode -> l;
		}
		p = tempNode;
		s = tempStack;
		return *this;
	}
	
	Node* tempNode1 = tempStack.top();
	if (tempNode == tempNode1 -> r){
		p = tempNode1;
		s = tempStack;
		return *this;
	}
	(tempStack).pop();
	if (tempNode == tempNode1 -> l){
		tempNode = tempNode1 -> l;
		while (true){
			(tempStack).push(tempNode);
			tempNode = tempNode -> l;
		}
		p = tempNode;
		s = tempStack;
		return *this;
	}
	return *this;	
	//account for this being your root
}     
//
//
//Tree::It Tree::It::operator--(int){ 
//	// Post-increment
////	Tree::It tempNew(Node* k, const stack<Node*>& g);
//	It tempNew(p, s);
//	tempNew.s = s;
//	if (p -> l){
//		(tempNew.s).push(tempNew.p);
//		tempNew.p = p -> l;
//		
//		while (tempNew.p -> r){
//			(tempNew.s).push(tempNew.p);
//			tempNew.p = tempNew.p -> r;
//		}
//			
//		return tempNew;
//	}
//	
//	Tree::Node* tempNode = (tempNew.s).top();
//	if (tempNew.p == tempNode -> l){
//		return It(tempNode, tempNew.s);
//	}
//	(tempNew.s).pop();
//	if (tempNew.p == tempNode -> r){
//		tempNew.p = tempNode -> r;
//		while (true){
//			(tempNew.s).push(tempNew.p);
//			tempNew.p = tempNew.p -> r;
//		}
//		return tempNew;
//	}
//	return tempNew;	
//	//account for this being your root
//}     
//
//Tree::It& Tree::It::operator--(){ 
//	// Post-increment
////	Tree::It tempNew(Node* k, const stack<Node*>& g);
//	It tempNew(p, s);
//	tempNew.s = s;
//	if (p -> l){
//		(tempNew.s).push(tempNew.p);
//		tempNew.p = p -> l;
//		
//		while (tempNew.p -> r){
//			(tempNew.s).push(tempNew.p);
//			tempNew.p = tempNew.p -> r;
//		}
//		p = tempNew.p;
//		s = tempNew.s;
//		return *this;
//	}
//	
//	Tree::Node* tempNode = (tempNew.s).top();
//	if (tempNew.p == tempNode -> l){
//		p = tempNode;
//		s = tempNew.s;
//		return *this;
//	}
//	(tempNew.s).pop();
//	if (tempNew.p == tempNode -> r){
//		tempNew.p = tempNode -> r;
//		while (true){
//			(tempNew.s).push(tempNew.p);
//			tempNew.p = tempNew.p -> r;
//		}
//		p = tempNew.p;
//		s = tempNew.s;
//		return *this;
//	}
//	return *this;	
//	//account for this being your root
//}  
//
//Tree::It Tree::It::operator+(long j) const{ //i could optimize this by skipping a subtree but....
//	It tempNew(p, s);
//	if (j > 0){
//		for (long i = 0; i < j; i++){
//			++tempNew;
//		}
//	}
//	if (j < 0){
//		for (long i = 0; i < j; i++){
//			--tempNew;
//		}
//	}
//	return tempNew;
//	
//	
//} // Get iterator to new location
//
//bool Tree::It::operator!=(const It& it) const{
//	if (it.p != p){
//		return true;
//	}
//	return false;
//}
//
//bool Tree::It::operator==(const It& it) const{
//	if (it.p != p){
//		return false;
//	}
//	return true;
//}
//
//Tree::It Tree::lo() const{
//	stack<Node*> stackTemp;
//	Node* temp = root;
//	while (temp -> l){
//		stackTemp.push(temp);
//		temp = temp -> l;
//	}
//	return It(temp, stackTemp);
//}
//
//Tree::It Tree::hi() const{
//	stack<Node*> stackTemp;
//	Node* temp = root;
//	while (temp -> r){
//		stackTemp.push(temp);
//		temp = temp -> r;
//	}
//	return It(temp, stackTemp);
//}
//
//size_t Tree::size() const{
//	return root->n;
//}
//
//bool Tree::empty() const{
//	if (!root){
//		return true;
//	}
//	return false;
//}
//
////Tree::It Tree::get(const string& key) const{
////	Node* temp = root;
////	while (true){
////		if 
////	}
////	
////}
//
//int main(){
//	cout << "hel" << "\n";
//	return 0;
//}
