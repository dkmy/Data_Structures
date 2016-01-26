//
//  mod.cpp
//  Data Structures Work
//
//  Created by David Kang Myung Yang on 9/10/15.
//  Copyright (c) 2015 David Kang Myung Yang. All rights reserved.
//

/*
 Assignment: Implement the following class. Make sure that it handles all signed 8-byte integers correctly and without overflow.
 
 For now, if the user attempts to divide by zero or set the modulus to something < 2, you can just "fail fast" with exit(-1).
 
 DUE: September 21, 2014 (by midnight!)
 */

//#ifndef ____Mod__
//#define ____Mod__

#include <iostream>
#include <cassert>
#include "mod.h"
#include <climits>
#include <cstdlib>
//#include <ctime>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;



long Mod::val() const { return x; } //accessor for the private x

Mod::Mod(long t) { //constructor. Taking mod in constructor lets us not worry about taking mods for every input later on.
	if (t < 0){
		x = (t % modulus + modulus) % modulus;
	}
	else{
		x = t % modulus;
	}
}

Mod::Mod(const Mod& m) { //copy constructor
	x = m.x;
}

Mod& Mod::operator=(const Mod& m){ //assignment
	x = m.val();
	return *this;
}

Mod& Mod::operator+=(const Mod& m){ //+=. One value is made negative so that the sum never overflows.
	long b = m.val();
	b = b - modulus;
	x = x + b;
	if (x < 0){
		x = x + modulus;
		return *this;
	}
	return *this;
}

Mod& Mod::operator-=(const Mod& m){ //similar idea with +
	long b = m.val();
	x = x - b;
	if (x < 0){
		x = x + modulus;
		return *this;
	}
	return *this;
}

Mod& Mod::operator*=(const Mod& m){ //repeated doubling is used for efficiency and prevention of overflow
	long b = m.val();
	Mod temp = 0; 
	while (b > 0){
		if (b % 2 == 1){
			temp += *this;
		}
		*this += *this;
		b = b / 2;
	}
	x = temp.val();
	return *this;
}

Mod Mod::inv(long r0){	 //extended euclidean algorithm. 
	long val_1 = modulus;
	long val_2 = r0;
	long coef_1_1 = 1;
	long coef_1_2 = 0;
	long coef_2_1 = 0;
	long coef_2_2 = 1;
	long q;
	long temp1;
	
	if (r0 == 0){ //division by 0
		cout << "inverting a 0" << "\n";
		exit(-1);
	}
	
	while (val_2 != 0){
		q = val_1 / val_2;
		temp1 = val_1;
		val_1 = val_2;
		val_2 = temp1 - q * val_2;
		
		temp1 = coef_1_1; 
		coef_1_1 = coef_1_2;
		coef_1_2 = temp1 - q * coef_1_2;
		
		temp1 = coef_2_1;
		coef_2_1 = coef_2_2;
		coef_2_2 = temp1 - q * coef_2_2;
	}
	if (val_1 != 1){ //coprime error
		cout << "Integer must be coprime to modulus" << "\n";
		exit(-1);
	}
	if (coef_2_1 < 0){
		coef_2_1 = (coef_2_1 % modulus + modulus) % modulus;
		Mod res = coef_2_1;
		return res;
	}
	Mod res = coef_2_1;
	return res;
}

Mod& Mod::operator/=(const Mod& m){ 
	return *this *= inv(m.val());
}

Mod Mod::operator-() const{
	long k = x;
	k = modulus - k;
	Mod ret(k);
	return ret;
}

Mod Mod::pwr(long e) const{ //exact same idea as *=. repeated squaring is used.

	if (e == 0){
		Mod prot = 1;
		return prot;
	}
	Mod prot = 0;
	if (e >= 0){
		Mod temp = x;
		prot = temp;
	}
	else{
		Mod temp = inv(x);
		prot = temp;
		e = e * -1;
	}
	Mod temp = 1;
	while (e > 0) {
		if(e % 2 == 1) {
			temp *= prot;
		}
		prot *= prot;
		e = e / 2;
	}
	return temp;
}

void Mod::set_modulus(long m){
	if (m < 2){ //exit for set modulus
		cout << "Modulus cannot be less than 2" << "\n";
		exit(-1);
	}
	modulus = m;
}


Mod operator+(const Mod& a, const Mod& b){
	Mod temp(a);
	temp += b;
	return temp;
}

Mod operator+(long t, const Mod& m){
	Mod ret(t);
	Mod ret2((ret += m).val());
	return ret2;
}

Mod operator-(const Mod& a, const Mod& b){
	Mod temp(a);
	temp -= b;
	return temp;
}

Mod operator-(long t, const Mod& m){
	Mod ret(t);
	Mod ret2((ret += m).val());
	return ret2;
}

Mod operator*(const Mod& a, const Mod& b){
	Mod temp(a);
	temp *= b;
	return temp;
}

Mod operator*(long t, const Mod& m){
	Mod ret(t);
	Mod ret2((ret *= m).val());
	return ret2;
}

Mod operator/(const Mod& a, const Mod& b){
	Mod temp(a);
	temp /= b;
	return temp;
}
Mod operator/(long t, const Mod& m){
	Mod ret(t);
	Mod ret2((ret *= m).val());
	return ret2;
}

bool operator==(const Mod& a, const Mod& b){
	return (a.val()==b.val());
}

bool operator==(long t, const Mod& m){
	return (t == m.val());
}

bool operator!=(const Mod& a, const Mod& b){
	return (!(a.val() == b.val()));
}

bool operator!=(long t, const Mod& m){
	return (!(t == m.val()));
}

istream& operator>>(istream& is, Mod& m) {
	long t;
	is >> t;
	m = t;
	return is;
}

ostream& operator<<(ostream& os, const Mod& m) {
	os << m.val();
	return os;
}

int main(){
//	cout << "Hello World" << "\n";
	Mod::set_modulus(17);
	Mod a = 0;
	cout << (a.pwr(1).val());
	
	
	return 0;
////	Mod::set_modulus(343);
////	Mod c = -1;
////	cout << (c.pwr(123454321)).val() << "\n";
////	
////	return 0;
//FILE * fp;
//fp = fopen("test.csv", "r");
//
//const char * printval = "value %s(%ld) != %s(%ld) case %d\n";
//int count = 0;
//long modulus, a, b, mod_a, mod_b, sum, difference, product, quotient, pwr;
//for (int i = 0; i < 96000; i++) {
//	// cout << i << "\n";
//	fscanf(fp, "%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld", &modulus, &a, &b, &mod_a, &mod_b, &sum, &difference, &product, &quotient, &pwr);
//	// printf("%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld\n", modulus, a, b, mod_a, mod_b, sum, difference, product, quotient, pwr);
//
//	// cout << modulus << "\n";
//	// cout << a << "\n";
//	// cout << b << "\n";
//
//	Mod::set_modulus(modulus);
//	Mod x(a);
//	Mod y(b);
//	count++;
//	if (x.val() != mod_a) {
//		count--;
//		printf(printval, "x.val", x.val(), "mod_a", mod_a, i);
//		// return -1;
//	}
//	count++;
//	if (y.val() != mod_b) {
//		count--;
//		printf(printval, "y.val", y.val(), "mod_b", mod_b, i); 
//		// return -1;
//	}
//	Mod s = (x + y);
//	// cout << "sum" << "\n";
//	count++;
//	if (s.val() != sum) {
//		count--;
//		printf(printval, "x + y", s.val(), "sum", sum, i);
//		// return -1;
//	}
//	// cout << "difference" << "\n";
//	Mod d = (x - y);
//	count++;
//	if (d.val() != difference) {
//		count--;
//		printf(printval, "x - y", d.val(), "difference", difference, i);
//		// return -1;
//	}
//	// cout << "product" << "\n";
//	Mod p = (x * y);
//	count++;
//	if (p.val() != product) {
//		count--;
//		printf(printval, "x * y", p.val(), "product", product, i);
//		// return -1;
//	}
//	// cout << "quotient" << "\n";
//	Mod q = (x / y);
//	count++;
//	if (q.val() != quotient) {
//		count--;
//		printf(printval, "x / y", q.val(), "quotient", quotient, i);
//		// return -1;
//	}
// cout << "pwr" << "\n";
//	Mod pw = x.pwr(b);
//	count++;
//	if (pw.val() != pwr) {
//		count--;
//		printf(printval, "x ^ y", pw.val(), "pwr", pwr, i);
//		// return -1;
//	}
//}
}