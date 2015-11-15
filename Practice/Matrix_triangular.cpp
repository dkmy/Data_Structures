#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > matrix_multi(vector<vector<int> > a, vector<vector<int> > b){
	if (a.size() != (b[0]).size()){
		cout << "can't do this " << "\n";
		exit(-1);
	}
	vector< vector<int> > out;
	for (int k = 0; k < b.size(); k++){
		vector<int> temp;
		for (int j = 0; j < a[0].size(); j++){
			int tempInt = 0;
			for (int i = 0; i < a.size(); i++){
				if (i<j){
					continue;
				}
				if (k<j){
					continue;
				}
				tempInt = tempInt + a[i][j] * b[k][i];
			}
			temp.push_back(tempInt);
		}
		out.push_back(temp);
	}
	return (out);
}

int main(){
	vector< vector<int> > a;
	for (int i = 0; i < 4; i ++){
		vector<int> temp;
		for (int k = 0; k < 4; k ++){
			if (i<k){
				temp.push_back(0);
				continue;
			}
			temp.push_back(k+1);
		}
		a.push_back(temp);
	}

	vector< vector<int> > b;
	for (int i = 0; i < 4; i ++){
		vector<int> temp;
		for (int k = 0; k < 4; k ++){
			if (i<k){
				temp.push_back(0);
				continue;
			}
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
	}
	
	for (int i=0; i<4;i++){
		for (int k=0;k<4;k++){
			cout << evenBetter[i][k] << " ";
		}
		cout << "\n";
	}
	
}