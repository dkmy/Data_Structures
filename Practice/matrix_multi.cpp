#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > matrix_multi(vector<vector<int> > a, vector<vector<int> > b){
	
	if (a.size() != (b[0]).size()){
		cout << "can't do ti " << "\n";
		exit(-1);
	}
	vector< vector<int> > output;
	for (int k = 0; k < b.size(); k++){
		vector<int> temp;
		for (int i = 0; i < a[0].size(); i++){
			int tempInt = 0;
			for (int j = 0; j < a.size(); j++){
				tempInt = tempInt + a[j][i] * b[k][j];
			}
//			cout << tempInt << "\n";
			temp.push_back(tempInt);
		}
		output.push_back(temp);
	}
	return (output);
}

int main(){
	vector< vector<int> > a;
	for (int i = 0; i < 3; i ++){
		vector<int> temp;
		for (int k = 0; k < 4; k ++){
			temp.push_back(k+1);
		}
		a.push_back(temp);
	}
	
	vector< vector<int> > b;
	for (int i = 0; i < 4; i ++){
		vector<int> temp;
		for (int k = 0; k < 3; k ++){
			temp.push_back(k+1);
		}
		b.push_back(temp);
	}
	
	vector<vector<int> > out = matrix_multi(a, b);
	
	
	vector<vector<int> > evenBetter;
	for (int k = 0 ; k < 4; k ++){
		vector<int> temptemp;
		for (int i = 0; i < 4; i++){
			temptemp.push_back(out[i][k]);
		}
		evenBetter.push_back(temptemp);
//		cout << "\n";
	}
	
	for (int i=0; i<4;i++){
		for (int k=0;k<4;k++){
			cout << evenBetter[i][k] << " ";
		}
		cout << "\n";
	}
	
}