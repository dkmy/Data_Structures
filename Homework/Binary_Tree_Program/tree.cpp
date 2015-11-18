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

Tree::Tree(){}
Tree::~Tree(){}

Tree::Entry::Entry(const string& key, double val) : key(key), val(val){} 

Tree::Entry::Entry(const Entry& e) : key(e.key), val(e.val) {}

Tree::Node::Node(const Entry& e, Node *l, Node *r, size_t n) : e(e), l(l), r(r), n(n) {}


Tree::Node::~Node(){}

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

void Tree::Node::kill(Node *p){
	stack<Node*> tempStack; //use stack like how we did for level-order on test
	tempStack.push(p);
	while (!tempStack.empty()){
		p = tempStack.top();
		tempStack.pop();
		if (p -> l){
			tempStack.push(p->l);
		}
		if (p -> r){
			tempStack.push(p->r);
		}
		delete p;
	}
}

double& Tree::It::operator*() const{
	return (p->e).val;
}

Tree::It Tree::It::operator++(int) {
	Tree::It backup = *this;
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
		return backup;
	}
	s.pop();
	if (p == s.top() -> l){
		p = s.top() -> l;
		while (true){
			(s).push(p);
			p = p -> l;
		}
		return backup;
	}
	return backup;	
}    

Tree::It& Tree::It::operator++() {
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
		return *this;
	}
	s.pop();
	if (p == s.top() -> l){
		p = s.top() -> l;
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
		return backup;
	}
	s.pop();
	if (p == s.top() -> r){
		p = s.top() -> r;
		while (true){
			(s).push(p);
			p = p -> r;
		}
		return backup;
	}
	return backup;	
}    

Tree::It& Tree::It::operator--() {
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
		return *this;
	}
	s.pop();
	if (p == s.top() -> r){
		p = s.top() -> r;
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
	for (long i = 0; i < j; i++) {
		++temp;
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

void Tree::It::del(bool erase) {
	if (!p){ //not even there lmao
		return;
	}	
	
	if (!p -> r && !p -> l){ //neither open, just delete
		if (s.top() -> l == p){
			s.top() -> l = 0;
			delete p;
		}
		if (s.top() -> r == p){
			s.top() -> r = 0;
			delete p;
		}
		p = s.top();
		s.pop();
	}
	
	if (p -> r && !p -> l){ //right is open
		if (s.top() -> l == p){
			s.top() -> l = p -> r;
			delete p;
		}
		if (s.top() -> r == p){
			s.top() -> r = p -> r;
			delete p;
		}
		Node *temp = p;
		p = p -> r;
		delete temp;
	}
	if (!p -> r && p -> l){ //left is open
		if (s.top() -> r == p){
			s.top() -> r = p -> l;
			delete p;
		}
		if (s.top() -> l == p){
			s.top() -> l = p -> l;
			delete p;
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
			tempParent -> l = 0; 
		}
		temp -> l = p -> l;
		temp -> r = p -> r;
		Node *trash = p;
		p = temp;
		delete trash;
	}
}

bool Tree::It::deleteAnother() {
	if (!p){ //not even there lmao
		return false;
	}	
	
	if (!p -> r && !p -> l){ //neither open, just delete
		if (s.top() -> l == p){
			s.top() -> l = 0;
			delete p;
		}
		if (s.top() -> r == p){
			s.top() -> r = 0;
			delete p;
		}
		p = s.top();
		s.pop();
		return true;
	}
	
	if (p -> r && !p -> l){ //right is open
		if (s.top() -> l == p){
			s.top() -> l = p -> r;
			delete p;
		}
		if (s.top() -> r == p){
			s.top() -> r = p -> r;
			delete p;
		}
		Node *temp = p;
		p = p -> r;
		delete temp;
		return true;
	}
	if (!p -> r && p -> l){ //left is open
		if (s.top() -> r == p){
			s.top() -> r = p -> l;
			delete p;
		}
		if (s.top() -> l == p){
			s.top() -> l = p -> l;
			delete p;
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
			tempParent -> l = 0; 
		}
		temp -> l = p -> l;
		temp -> r = p -> r;
		Node *trash = p;
		p = temp;
		delete trash;
		return true;
	}
	return false;
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
	It temp = lo();
	while (temp.p && ((temp.p)->e).key != key) {		
		++temp;	
	}
	return temp;
}

bool Tree::set(const string& key, double val){
	if (!root){
		Node* temp = new Node(Entry(key, val));
		root = temp;
		return false;
	}
	It temp = lo();
	It end = hi(); //don't wanna fall off!
	while (temp != end){
		if (((temp.p)->e).key < key){
			++temp;
		}
		else{
			break;
		}
	}
	if (((temp.p)->e).key == key){ //easy part
		((temp.p)->e).val = val;
		return true; 
	}
	
	if (((temp.p)->e).key > key){ //create new
		Node *addition = new Node(Entry(key, val));
		(temp.p) -> l = addition;
		--temp;
		return false; //or is it true?
	}
	
	if (((temp.p)->e).key < key){ //create new
		Node *addition = new Node(Entry(key, val));
		(temp.p) -> r = addition;
		++temp;
		return false; //or is it true?
	}
	return false;
}

bool Tree::del(const string& key) {
	It temp = this -> get(key);
	return (temp.deleteAnother());
}


Tree::It Tree::none() const { //root
	stack<Node*> temp = stack<Node*>();
	temp.push(root);
	return It(0, temp);
}

int main(){
	cout << "hel" << "\n";
	return 0;
}
