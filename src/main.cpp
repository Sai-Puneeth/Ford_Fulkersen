#include<bits/stdc++.h>
#include <chrono> 
#include "Ford_Fulkersen.h"
#include "Graph.h"

#define ll long long int
using namespace std;
using namespace std::chrono; 

bool fileReadInput = true;

int main(int argc, const char** argv) {
    ifstream in("../data/1.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf());

    // reading the input
    ll nodes_no;
    if(!fileReadInput){
		cout<<"Enter the number of nodes"<<endl;
		cout<<"=========================="<<endl;
	}
	cin>>nodes_no;

	ll edges_no;
	if(!fileReadInput){
		cout<<"Enter the number of edges"<<endl;
		cout<<"=========================="<<endl;
	}
	cin>>edges_no;

	vector<ll> nodes;
	vector<vector<ll>> edges;
	vector<ll> weights;

	//Making nodes vector
	for(ll i=0;i<nodes_no;i++){
		nodes.push_back(i);
	}

	if(!fileReadInput)
		cout<<"Enter the edges(0 is the first vertex):"<<endl;
	for(ll i=0;i<edges_no;i++){
		vector<ll> v;	ll a,b,c;
		cin>>a;	cin>>b; cin>>c;	v.push_back(a);v.push_back(b);weights.push_back(c);
		edges.push_back(v);
	}

	if(!fileReadInput)
		cout<<"=========================="<<endl;

	Graph *G;
	G = new Graph(nodes,edges,weights);
	G->printG(0);

	cout<<"STARTED!!!!!!"<<endl;
	// your function HERE
	cout<<"COMPLETE!!!!!!"<<endl;

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}