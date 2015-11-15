//9.18.15
//how do we make interfaces?

class X {
	virtual void f(double x) =0 //pure virtual
};

class Y : public X{
	void f(double x) { return x+17;}
};

class Z: public Y{
	void f(double x) { return y::f(x) + 29;}
};

//you don't want to 
//X x = Y(); 
//Y y = (Y) x;
//beware of slicing

X *px = new Y(); //make defarult constructor for Y, but point to X in order to prevent slicing

X& rx = *px; //reference

//say we want to compute an integral. Try using romberg method

template <class F>

//import cmath
double sin_wrapper(double x){
	return sin(x);
}

double operator() (double x){
	//compute infinite series
}

double romberg (F f, double a, double b){
	//content
}

double y = romberg(sin_wrapper, 0, M_PI); //pointer
double z = romberg(Sin, 0, M_PI);  //class name

//Root finding: Bisection algorithm This 2^-n is called linear convergence while 2^-2^n is called a quadratic convergence.
//A cool algo: (x1, y1), (x2, y2), 

//while (x1-x2) < epsilon, max{x1, x2}
//compute (x3, y3) by lin interporlation. if y2*y3 < 0 (different side), replace (x1, y1) by (x2, y2), (x2, y2) by (x3, y3)
//else, y1 *= 0.5, replace (x2, y2) by (x3, y3)
w
//okay so here's the algorithm. You have a curve and you know a point on curve less than 0, greater than 0. Call them A and B respectively. 
//You make linear interpoaltion or line between A and B. It hits 0 at certain x. do f(x), find the new y. Replace this with A. Divide B by 2. Repeat until the difference between a.x and b.x is less than epsilon.

//quadratic convergence
template <class F>
const double epsilon = 1E-14;
double solve(F f, double x1, double x2){
	while abs(x1-x2) > epsilon 
	y1 = linInterp(x1)
	y2 = linInterp(x2)
	
	if (y2 * y3 <= 0){
		replace (x1, y1) by (x2, y2)
				(x2, y2) by (x3, y3)
	}
	
	else{
		y1 *= 0.5
		replace (x2, y2) by (x3, y3)
	}
	
	
}





