/*

Input FIle: scmpts.in nm
f1 t1
f2 t2
...
f_m t_m
where
n = # of vertices
m = # of directed arcs
f_i t_i indicates an arc from vertex f_i to vertex t_i
Output File: scmpts.out nc
s_1 s_2 ... s_nc
v_1,1 ... v_1,s_1
...
v_nc,1 ... v_nc, s_nc
na
p_1 q_1 ...
p_na q_na
where
nc = # of strong components
s_i = # of vertices in ith strong component
v_i,j = jth vertex in ith strong component
na = # of arcs in the component graph
p_i q_i indicates an arc from (component) vertex p_i to (component) vertex q_i
Note: Strong components should be numbered in topological order, i.e. so that p_i < q_i, always.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;

typedef vector<int> VI;
typedef vector< vector<int> > VVI;

VI stored_v;
VB visited;
VB visited_rev;

VB visited_C;
VI stored_C;

VI path;

void frontDFS(int start, VVI graph){
	if (visited[start]){
		return;
	}
	visited[start] = 1;
	for (int j=0; j < graph[start].size(); j++){
		if (!visited[graph[start][j]]){
			frontDFS(graph[start][j], graph);
		}
	}
	stored_v.push_back(start);
}

void revDFS(int start, VVI g){
	if (visited_rev[start]){
		return;
	}
	visited_rev[start] = 1;
	for (int j=0; j < g[start].size(); j++){
		if (!visited_rev[g[start][j]]){
			revDFS(g[start][j], g);
		}
	}
	path.push_back(start);
	return;
}

void cDFS(int start, VVI graph){
	if (visited_C[start]){
		return;
	}
	visited_C[start] = 1;
	for (int j=0; j < graph[start].size(); j++){
		if (!visited_C[graph[start][j]]){
			frontDFS(graph[start][j], graph);
		}
	}
	stored_C.push_back(start);
}

int main(int argc, char *argv[]) {
	ifstream fin("scmpts.in");
	ofstream fout("scmpts.out");
	
	int N, M;
	fin >> N >> M;
	
	VVI graph;
	VVI graph_T;
	VVI clusters;
	VVI CG;
	VVB cluster_bool;
	
	VI temp;
	for (int j=0; j<N;j++){
		graph.push_back(temp);
		graph_T.push_back(temp);
	}
//	cout << "HI" << "\n";
	int t1, t2;
	for (int i=0; i<M; i++){
		fin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph_T[t2].push_back(t1);
	}
	
//	cout << "HI" << "\n";
	visited = VB(N, 0);
	visited_rev = VB(N, 0);
	
//	cout << "HI" << "\n";
	for (int i=0; i < N; i++){
		if (!visited[i]){
			frontDFS(i, graph);
		}
	}
//	cout << "HI" << "\n";
	for (int i=0; i < N; i++){
		if (visited_rev[stored_v[N-i-1]]){
			continue;
		}
		path.clear();
		if (!visited_rev[stored_v[N-i-1]]){
			revDFS(stored_v[N-i-1], graph_T);
		}
		clusters.push_back(path);
	}
//	cout << " HI" << "\n";
	for (int j=0; j<clusters.size(); j++){
		for (int i=0; i < clusters[j].size(); i++){
		}
	}
	
//	cout << "HI" << "\n";
	
	for (int i=0; i<clusters.size(); i++){
		VB tempCB = VB(N, 0);
		for (int j=0; j < clusters[i].size(); j++){
			tempCB[clusters[i][j]] = 1;
		}
		cluster_bool.push_back(tempCB);		
	}
	
	int arcs = 0;
	for (int i=0; i< clusters.size(); i++){
		CG.push_back(temp);
	}
	
	for (int i=0; i< clusters.size(); i++){
		for (int j=0; j<clusters[i].size(); j++){
			for (int k = 0; k < graph[clusters[i][j]].size(); k++){
				int tempAdd = graph[clusters[i][j]][k];
				if (cluster_bool[i][tempAdd]){
					continue;
				}
				else{
					for (int s = 0; s < clusters.size(); s++){
						if (cluster_bool[s][tempAdd]){
							CG[i].push_back(s);
							arcs++;
						}
					}
				}
			}
		}
	}
	visited_C = VB(clusters.size(), 0);
	for (int i=0; i < clusters.size(); i++){
		if (!visited_C[i]){
			cDFS(i, CG);
		}
	}
	
	fout << clusters.size();
	fout << "\n";
	for (int i=0; i<clusters.size(); i++){
		fout << clusters[i].size() << " ";
	}
//	fout << "\n";
	fout << "\n";
	for (int i=0; i < clusters.size(); i++){
		for (int j=0; j < clusters[i].size(); j++){
			fout << clusters[i][j] << " ";
		}
		fout << "\n";
	}
//	fout << "\n";
	fout << arcs;
	fout << "\n";
	for (int i=0; i<clusters.size(); i++){
		for (int j=0; j<CG[stored_C[clusters.size()-i-1]].size(); j++){
			fout << stored_C[clusters.size()-i-1]  << " " << CG[stored_C[clusters.size()-i-1]][j] ;
			fout << "\n";
		}
		
	}
	
	
	fout.close();
	return 0;
	
}