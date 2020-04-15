#pragma once
#include <bits/stdc++.h>
using namespace std;

/*!
Graph class represents the blueprint of a graph.
It contains the node vector,edges vector, the adjacency matrix and the adjacency matrix of the transpose
as its member variables.
Its Constructor takes in the node vector and the edge pairs vector as its input parameters and stores them.
It also iniatializes the G and GT of the Graph 
*/
class Graph{
	public:
		vector <long long int > nodes;
		vector <vector<long long int > > edges;
		vector <long long int > weights;
		vector <vector<long long int>> G;
		vector <vector<long long int>> GT;
		long long int max;
		/*!
		Its Constructor takes in the node vector and the edge pairs vector as its input parameters and stores them.
		It also iniatializes the G and GT of the Graph 
		*/
		Graph(vector<long long int> N, vector<vector<long long int>> E, vector <long long int > W){

			for(auto i:N){
				nodes.push_back(i);
			}
			for(auto row:E){
				vector<long long int> v6;
				v6.push_back(row[0]);	v6.push_back(row[1]);
				edges.push_back(v6);
			}
			for(auto i:W){
				weights.push_back(i);
			}

			if(nodes.size()!=0){
			max = *max_element(nodes.begin(), nodes.end())+1;
			initGandGT();
			makeGandGT();
		}
		}

		void initGandGT();
		void makeGandGT();
		void printG(int trans);
		long long int  sink();
		long long int source();

};

/*!
This function clear the G and GT adjacency matices and allocates the required space to them
*/

void Graph :: initGandGT(){
	G.clear();
	G.resize(max, vector<long long int> (max,0));
	GT.clear();
	GT.resize(max, vector<long long int> (max,0));
	return;
}

/*!
This function prints the adjacency matix of the graph or its transpose.
@Parameter: int trans
If trans=1 the transpose matrix is printed
If trans = 0
*/

void Graph :: printG(int trans){
	if(!trans){
		for(auto i: G){
			for(auto j:i){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	else{
		for(auto i: GT){
			for(auto j:i){
				cout<<j<<" ";
			}
			cout<<endl;
		}	
	}
	return;
}

void Graph :: makeGandGT(){
	long long int a,b;
	for(long long int i=0;i<edges.size();i++){
		a=edges[i][0];	b=edges[i][1];
		G[a][b] = weights[i];
	}
	return;
}

long long int Graph :: source(){
	long long int sum=0;
	for(long long int i=0;i<nodes.size();i++){
		for(long long int j=0;j<nodes.size();j++){
			sum+=G[j][i];
		}
		if(sum == 0){
			cout<<i<<endl;
			return i;	
		}
		else{sum=0;}
	}
}

long long int Graph :: sink(){
	long long int sum=0;
	for(long long int i=0;i<nodes.size();i++){
		for(long long int j=0;j<nodes.size();j++){
			sum+=G[i][j];
		}
		if(sum == 0){
			cout<<i<<endl;
			return i;	
		}
		else{sum=0;}
	}
}