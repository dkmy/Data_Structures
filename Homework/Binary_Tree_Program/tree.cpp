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

Tree::Tree(){
	root = 0;
//	root -> n = 0;
}
Tree::~Tree(){}

Tree::Entry::Entry(const string& key, double val) : key(key), val(val){} 

Tree::Entry::Entry(const Entry& e) : key(e.key), val(e.val) {}

Tree::Node::Node(const Entry& e, Node *l, Node *r, size_t n) : e(e), l(l), r(r), n(n) {}


Tree::Node::~Node(){
	l = NULL;
	r = NULL;
}

Tree::It::It(const It& i) : p(i.p), s(i.s) {}


Tree::It::It(Node *p, const stack<Node*>& s){
	this->p = p;
	this->s = s;
}

Tree::It::~It(){
	while (!s.empty()){
		s.pop();
	}
}
Tree::It Tree::none() const { //root
	stack<Node*> temp = stack<Node*>();
	temp.push(root);
	return It(0, temp);
}

void Tree::Node::kill(Node *p){
	stack<Node*> tempStack; //use stack like how we did for level-order on test
	tempStack.push(p);
	Node* tempNode = p;
	while (!tempStack.empty()){
		tempNode = tempStack.top();
		tempStack.pop();
		if (tempNode -> l){
			tempStack.push(tempNode->l);
		}
		if (tempNode -> r){
			tempStack.push(tempNode->r);
		}
		delete tempNode;
	}
}

double& Tree::It::operator*() const{
	return (p->e).val;
}

Tree::It Tree::It::operator++(int) {
	Tree::It backup = *this;
	if (p == 0){
		Node* tempStart = s.top();
		while(tempStart -> l){
			tempStart = tempStart -> l;
			s.push(tempStart);
		}
		p = tempStart;
		return backup;
	}
	
	
	//make a temporary stack that goes upp the way up.
	stack<Node*> tempRootCheck = s;
	Node* tempRootNode = p;

	if (!p->r && !tempRootCheck.empty()){
		
		while (!tempRootCheck.empty() && tempRootCheck.top()->r == tempRootNode){
			tempRootNode = tempRootCheck.top();
			tempRootCheck.pop();
		}
		
		if (tempRootCheck.empty()){
			stack<Node*> temp = stack<Node*>();
			temp.push(tempRootNode);
			p = 0;
			s = temp;
			return backup;
		}
	}
	if (!p->r && tempRootCheck.empty()){ //you were at the last
//		cout << p->e.val << "\n";

		stack<Node*> tempNewStack;
		tempNewStack.push(tempRootNode);
		while (tempRootNode -> l){
			tempRootNode = tempRootNode -> l;
			tempNewStack.push(tempRootNode);
		}
		p = tempRootNode;
		s = tempNewStack;
		return backup;
	}
	
	if (p -> r){
		s.push(p);
		p = p -> r;
		while (p -> l){
			s.push(p);
			p = p -> l;
		}
		return backup;
	}
	if (p == s.top() -> r){
		while (p == s.top() -> r){
			p = s.top();
			s.pop();
		}
		if (s.empty()){ //last member of in_order
			stack <Node*> RootStack;
			RootStack.push(p);
			p = 0;
			s = RootStack;
			return backup;
		}
		p = s.top();
		s.pop();
		return backup;
	}
	
	if (p == s.top() -> l){
		if (!s.top() -> r){
			p = s.top();
			s.pop();
			return backup;
		}
		p = s.top() -> r;
		
		while (true){
			(s).push(p);
			p = p -> l;
		}	
		return backup;
	}
	return backup;	
}  
 

Tree::It& Tree::It::operator++() {
	Tree::It backup = *this;
	if (p == 0){
		Node* tempStart = s.top();
		while(tempStart -> l){
			tempStart = tempStart -> l;
			s.push(tempStart);
		}
		p = tempStart;
		return *this;
	}
	
	
	//make a temporary stack that goes upp the way up.
	stack<Node*> tempRootCheck = s;
	Node* tempRootNode = p;

	if (!p->r && !tempRootCheck.empty()){
		
		while (!tempRootCheck.empty() && tempRootCheck.top()->r == tempRootNode){
			tempRootNode = tempRootCheck.top();
			tempRootCheck.pop();
		}
		
		if (tempRootCheck.empty()){
			stack<Node*> temp = stack<Node*>();
			temp.push(tempRootNode);
			p = 0;
			s = temp;
			return *this;
		}
	}
	if (!p->r && tempRootCheck.empty()){ //you were at the last
//		cout << p->e.val << "\n";

		stack<Node*> tempNewStack;
		tempNewStack.push(tempRootNode);
		while (tempRootNode -> l){
			tempRootNode = tempRootNode -> l;
			tempNewStack.push(tempRootNode);
		}
		p = tempRootNode;
		s = tempNewStack;
		return *this;
	}
	
	if (p -> r){
		s.push(p);
		p = p -> r;
		while (p -> l){
			s.push(p);
			p = p -> l;
		}
		return *this;
	}
	if (p == s.top() -> r){
		while (p == s.top() -> r){
			p = s.top();
			s.pop();
		}
		if (s.empty()){ //last member of in_order
			stack <Node*> RootStack;
			RootStack.push(p);
			p = 0;
			s = RootStack;
			return *this;
		}
		p = s.top();
		s.pop();
		return *this;
	}
	
	if (p == s.top() -> l){
		if (!s.top() -> r){
			p = s.top();
			s.pop();
			return *this;
		}
		p = s.top() -> r;
		
		while (true){
			(s).push(p);
			p = p -> l;
		}	
		return *this;
	}
	return *this;	
}    

Tree::It Tree::It::operator--(int) {
	Tree::It backup = *this;
	if (p == 0){
		Node* tempStart = s.top();
		if (tempStart -> r){
			tempStart = tempStart -> r;
		}
		while(tempStart -> r){
			s.push(tempStart);
			tempStart = tempStart -> r;
		}
		p = tempStart;
		return backup;
	}
//	bool tempBool = false;
//	if (*(*this) == 12){
//		tempBool = true;
//		stack<Node*> what = s;
//	
//	}
	
	//make a temporary stack that goes upp the way up.
	stack<Node*> tempRootCheck = s;
	Node* tempRootNode = p;
	
	if (!p->l){
		while (!tempRootCheck.empty() && tempRootCheck.top()->l == tempRootNode){
			tempRootNode = tempRootCheck.top();
			tempRootCheck.pop();
		}
		
		if (tempRootCheck.empty()){
			stack<Node*> temp = stack<Node*>();
			temp.push(tempRootNode);
			p = 0;
			s = temp;
			return backup;
		}
	}

	if (!p->l && tempRootCheck.empty()){ //you were at the last
//		cout << p->e.val << "\n";
		
		stack<Node*> tempNewStack;
		tempNewStack.push(tempRootNode);
		while (tempRootNode -> r){
			tempRootNode = tempRootNode -> r;
			tempNewStack.push(tempRootNode);
		}
		p = tempRootNode;
		s = tempNewStack;
		return backup;
	}
	
	if (p -> l){
	
		s.push(p);
		p = p -> l;
		while (p -> r){
			s.push(p);
			p = p -> r;
		}
		return backup;
	}
	if (p == s.top() -> l){

		while (p == s.top() -> l){
			p = s.top();
			s.pop();
		}
		if (s.empty()){ //last member of in_order
			stack <Node*> RootStack;
			RootStack.push(p);
			p = 0;
			s = RootStack;
			return backup;
		}
		p = s.top();
		s.pop();
		return backup;
	}
	
	if (p == s.top() -> r){
		if (!s.top() -> l){
			p = s.top();
			s.pop();
			return backup;
		}
		p = s.top() -> l;
		
		while (true){
			(s).push(p);
			p = p -> r;
		}	
		return backup;
	}
	return backup;	
}    
 

Tree::It& Tree::It::operator--() {
	Tree::It backup = *this;
	if (p == 0){
		Node* tempStart = s.top();
		if (tempStart -> r){
			tempStart = tempStart -> r;
		}
		while(tempStart -> r){
			s.push(tempStart);
			tempStart = tempStart -> r;
		}
		p = tempStart;
		return *this;
	}
//	bool tempBool = false;
//	if (*(*this) == 12){
//		tempBool = true;
//		stack<Node*> what = s;
//	
//	}
	
	//make a temporary stack that goes upp the way up.
	stack<Node*> tempRootCheck = s;
	Node* tempRootNode = p;
	
	if (!p->l){
		while (!tempRootCheck.empty() && tempRootCheck.top()->l == tempRootNode){
			tempRootNode = tempRootCheck.top();
			tempRootCheck.pop();
		}
		
		if (tempRootCheck.empty()){
			stack<Node*> temp = stack<Node*>();
			temp.push(tempRootNode);
			p = 0;
			s = temp;
			return *this;
		}
	}

	if (!p->l && tempRootCheck.empty()){ //you were at the last
//		cout << p->e.val << "\n";
		
		stack<Node*> tempNewStack;
		tempNewStack.push(tempRootNode);
		while (tempRootNode -> r){
			tempRootNode = tempRootNode -> r;
			tempNewStack.push(tempRootNode);
		}
		p = tempRootNode;
		s = tempNewStack;
		return *this;
	}
	
	if (p -> l){
	
		s.push(p);
		p = p -> l;
		while (p -> r){
			s.push(p);
			p = p -> r;
		}
		return *this;
	}
	if (p == s.top() -> l){

		while (p == s.top() -> l){
			p = s.top();
			s.pop();
		}
		if (s.empty()){ //last member of in_order
			stack <Node*> RootStack;
			RootStack.push(p);
			p = 0;
			s = RootStack;
			return *this;
		}
		p = s.top();
		s.pop();
		return *this;
	}
	
	if (p == s.top() -> r){
		if (!s.top() -> l){
			p = s.top();
			s.pop();
			return *this;
		}
		p = s.top() -> l;
		
		while (true){
			(s).push(p);
			p = p -> r;
		}	
		return *this;
	}
	return *this;	
}    


Tree::It Tree::It::operator+(long j) const{ //i could optimize this by skipping a subtree but....
	It temp = *this;
	if (j > 0){
		for (long i = 0; i < j; i++) {
			++temp;
		}
	}
	if (j < 0){
		j = j * -1;
		for (long i = 0; i < j; i++){
			--temp;
		}
	}
	return temp;
} // Get iterator to new location

bool Tree::It::operator!=(const It& it) const{
	if (it.p != p){
		return true;
	}
	return false;
}

bool Tree::It::operator==(const It& it) const{
	if (it.p != p){
		return false;
	}
	return true;
}

void Tree::changeRoot(Node* k){
	root = k;
}

void Tree::It::del(bool erase) { //please don't use this . please dont.

if (!p){ //not even there lmao
		return;
	}	
	
	
	if (!p -> r && !p -> l){ //neither open, just delete
		
		bool tempBool = false;
//		if (p == root){
//			tempBool = true;
//		}
		if (s.top() -> l == p){
			s.top() -> l = 0;
		}
		if (s.top() -> r == p){
			s.top() -> r = 0;
		}
		Node* tempDeleter = p;
		delete tempDeleter;
		p = s.top();
//		if (tempBool){
//			root = p;
//		}
		s.pop();
	}
	
	if (p -> r && !p -> l){ //right is open I'M ON HERE FUDGE		
		if (s.empty()){
			Node *temp = p;
			p = p -> r;
			delete temp;
//			changeRoot(p);
		}
		if (s.top() -> l == p){
			s.top() -> l = p -> r;
		}
		if (s.top() -> r == p){
			s.top() -> r = p -> r;
		}
		
		Node *temp = p;
		p = p -> r;
		
		delete temp;
	}
	
	if (!p -> r && p -> l){ //left is open
		if (s.empty()){
					Node *temp = p;
					p = p -> l;
					delete temp;
		//			changeRoot(p);
				}
		if (s.top() -> r == p){
			s.top() -> r = p -> l;
		}
		if (s.top() -> l == p){
			s.top() -> l = p -> l;
		}
		Node *temp = p;
		p = p -> l;
		
		delete temp;
	}
	
	if (p -> r && p -> l){ //lo of the right subtree is the new p
		Node *temp = p;
		temp = temp -> r;
		Node *tempParent = p;
		while (temp -> l){
			tempParent = temp;
			temp = temp -> l;
		}
		//tempParent is parent of temp now
		if (p != tempParent){
			tempParent -> l = temp -> r;  //if the leftmost of subtree has a right child
		}
		temp -> l = p -> l;
		temp -> r = p -> r;
		Node *trash = p;
		p = temp;
		delete trash;
	}
}




size_t Tree::size() const{
	return root->n;
}

bool Tree::empty() const{
	if (!root){
		return true;
	}
	return false;
}

bool Tree::check_sizes() const{ // ?????????????????? ??!??!?!??!?!?!?!?!?!??!?!?!
	return true; //?!?!?!?!??!?!?!??!!??!?!??!?!?!?
}

Tree::It Tree::lo() const{
	stack<Node*> stackTemp;
	Node* temp = root;
	while (temp -> l){
		stackTemp.push(temp);
		temp = temp -> l;
	}
	return It(temp, stackTemp);
}

Tree::It Tree::hi() const{
	stack<Node*> stackTemp;
	Node* temp = root;
	while (temp -> r){
		stackTemp.push(temp);
		temp = temp -> r;
	}
	return It(temp, stackTemp);
}

Tree::It Tree::get(const string& key) const {
//	It temp = lo(); //i have a feeling that i will get an F with this method
//	while (temp.p && ((temp.p)->e).key != key) {		
//		++temp;	
//	}
//	return temp;
	
	stack<Node*> tempStack;
	Node* tempNode = root;
	Tree::It traverser(tempNode, tempStack);
	
	while (traverser.p && ((traverser.p)->e).key != key){
		if ((traverser.p->e.key).compare(key) < 0){
			++traverser;
		}
		else{
			--traverser;
		}
	}
	return traverser;
	
	
}

bool Tree::set(const string& key, double val){
//	cout << root -> n << "\n";
	if (!root){
		cout << "here maybe" << "\n";
		Node* temp = new Node(Entry(key, val));
		root = temp;
		root -> n = 1;
		return true;
	}

	stack<Node*> tempStack;
	Node* tempNode = root;
	Tree::It temp(tempNode, tempStack);
	It end = hi();
	while (temp != end && temp.p && ((temp.p)->e).key != key){
		if ((temp.p->e.key).compare(key) < 0){
			temp.s.push(temp.p);
			++temp;
		}
		else{
			temp.s.push(temp.p);
			--temp;
		}
	}
	
	if (((temp.p)->e).key == key){ //easy part
		((temp.p)->e).val = val;
		return true; 
	}
	
	if (((temp.p)->e).key > key){ //create new
		cout << "r" << "\n";
		Node *addition = new Node(Entry(key, val));
		(temp.p) -> l = addition;
		addition -> n = 1;
		It tempIt = this -> get(key);
		while (!tempIt.s.empty()){
			tempIt.s.top() -> n = (tempIt.s.top() -> n) + 1;
			tempIt.s.pop();
		}
//		temp.s.push(temp.p);
//		while (!temp.s.empty()){
//			temp.s.top() -> n = (temp.s.top() -> n) + 1;
//			temp.s.pop();
//		}
//		--temp;
		return true; //or is it true?
	}
	
	else if (((temp.p)->e).key < key){ //create new
		Node *addition = new Node(Entry(key, val));
		(temp.p) -> r = addition;
		addition -> n = 1;
		stack<Node*> tempUpper = temp.s;
		It tempIt = this -> get(key);
		while (!tempIt.s.empty()){
			tempIt.s.top() -> n = (tempIt.s.top() -> n) + 1;
			tempIt.s.pop();
		}
//		tempUpper.push(temp.p);
//		while (!tempUpper.empty()){
//			cout << key << " " << tempUpper.top() -> e.val << " " << tempUpper.top() -> n << "\n";
//			tempUpper.top() -> n = (tempUpper.top() -> n) + 1;
//			tempUpper.pop();
//		}
//		++temp;
		return true; //or is it true?
	}
	return false;
}

bool Tree::del(const string& key) {
	It tempIt = this -> get(key);
	Node* p = tempIt.p;
	stack<Node*> s = tempIt.s;
	bool tempBool = false;
	if (p == root){
		tempBool = true;
	}
	
	if (!p){ //not even there lmao
		return false;
	}	
	
	It tempD = this -> get(key);
	while (!tempD.s.empty()){
		tempD.s.top() -> n = (tempD.s.top() -> n) - 1;
		tempD.s.pop();
	}
	
	if (!p -> r && !p -> l){ //neither open, just delete
		if (tempBool){
			cout << "deleting tree..." << "\n";
			root -> n = 0;
			Node* tempDeleter;
			delete tempDeleter;
			root = 0;
		}
		if (s.top() -> l == p){
			
			s.top() -> l = 0;
		}
		if (s.top() -> r == p){
			
			s.top() -> r = 0;
		}
		Node* tempDeleter = p;
		delete tempDeleter;
		p = s.top();
		if (tempBool){
			root = p;
		}
		s.pop();
		return true;
	}
	
	if (p -> r && !p -> l){ //right is open I'M ON HERE FUDGE	
		if (s.empty()){
			Node *temp = p;
			p = p -> r;
			delete temp;
			if (tempBool){
				root = p;
			}
			return true;
		}
		if (s.top() -> l == p){
			s.top() -> l = p -> r;
		}
		if (s.top() -> r == p){
			s.top() -> r = p -> r;
		}
		
		Node *temp = p;
		p = p -> r;
		
		delete temp;
		return true;
	}
	
	if (!p -> r && p -> l){ //left is open
		if (s.empty()){
			Node *temp = p;
			p = p -> l;
			delete temp;
			if (tempBool){
				root = p;
			}
			return true;
		}
		if (s.top() -> r == p){
			s.top() -> r = p -> l;
		}
		if (s.top() -> l == p){
			s.top() -> l = p -> l;
		}
		Node *temp = p;
		p = p -> l;
		
		delete temp;
		return true;
	}
	
	if (p -> r && p -> l){ //lo of the right subtree is the new p
		Node *temp = p;
		temp = temp -> r;
		Node *tempParent = p;
		while (temp -> l){
			tempParent = temp;
			temp = temp -> l;
		}
		//tempParent is parent of temp now
		if (p != tempParent){
			tempParent -> l = temp -> r;  //if the leftmost of subtree has a right child
		}
		temp -> l = p -> l;
		temp -> r = p -> r;
		Node *trash = p;
		p = temp;
		if (tempBool){
			root = p;
		}
		delete trash;
		return true;
	}
	return false;
}

int main() {
	Tree tree;
	tree.set("A", 1);
	tree.set("B", 2);
	tree.set("C", 3);
	tree.set("D", 4);
	tree.set("E", 5);
	tree.set("F", 6);
	tree.set("G", 7);
	tree.set("H", 8);
	tree.set("I", 9);
	tree.set("J", 10);
	tree.set("K", 11);
	tree.set("L", 12);
	tree.del("A");
	tree.del("C");
//	++tree.hi();
	std::cout << *(--------tree.lo()) << "\n";
	cout << tree.size() << "\n";
	
	/*
	addition works
	sentry "safenet" node works
	going to hi() and lo() from sentry node also works
	subtraction works
	+ k works
	- k works
	delete works
	deleting root works
	delete root and adding more works
	tree.size works in every possible case
	

	
	*/
	return 0;
}

