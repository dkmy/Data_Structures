#include <iostream>
#include <vector>

using namespace std;

double innerProd(vector<double> a, vector<double> b){
	int prod = 0;
	for (int i = 0; i < a.size(); i++){
		prod += (a[i] * b[i]);
	}
	return prod;
}

double component(vector<double> a, vector<double> b){
	return (innerProd(a, b)/innerProd(b,b));
}

vector<double> multi(double a, vector<double> b){
	vector<double> out;
	for (int i=0; i<b.size(); i++){
		out.push_back(a*b[i]);
	}
	return out;
}

vector<double> subtract(vector<double> a, vector<double> b){
	vector<double> out;
	for (int i=0; i<b.size(); i++){
		out.push_back(a[i]-b[i]);
	}
	return out;
}

int main(int argc, char *argv[]) {
	vector<vector<double> > subspace;
	vector<double> a;
	a.push_back(1);
	a.push_back(-1);
	a.push_back(1);
	a.push_back(-1);
	subspace.push_back(a);
	vector<double> b;
	b.push_back(5);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	subspace.push_back(b);
	vector<double> c;
	c.push_back(-3);
	c.push_back(-3);
	c.push_back(1);
	c.push_back(-3);
	subspace.push_back(c);
	
	vector<vector<double> > orthogonalized;
	cout << "rea" << "\n";
	for (int i=0; i<subspace.size(); i++){
		orthogonalized.push_back(subspace[i]);
		vector<double> temp = subspace[i];
		for (int j=0; j<orthogonalized.size()-1; j++){
			orthogonalized[i] = subtract(orthogonalized[i], multi(component(subspace[i], orthogonalized[j]), orthogonalized[j]));
			cout << component(subspace[i], orthogonalized[j]) << "\n";
		}
		
//		cout << 
	}
	
	for (int i=0; i<3; i++){
		for (int j=0; j<4; j++){
			cout << orthogonalized[i][j] << " ";
		}
		cout << "\n";
	}
	
}