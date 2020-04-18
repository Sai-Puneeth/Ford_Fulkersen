#include<bits/stdc++.h>
#include <chrono> 
#include "Ford_Fulkersen.h"
#include "Graph.h"

#define ll long long int
using namespace std;
using namespace std::chrono; 

bool fileReadInput = true;

int main(int argc, const char** argv) {
    // ifstream in("../data/Newman-Cond_mat_95-99-two_mode.txt");
	ifstream in("../data/3.txt");
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
	for(ll i=0;i<nodes_no+2;i++){           // changed nodes_no to nodes_no +2
		nodes.push_back(i);
	}

	if(!fileReadInput)
		cout<<"Enter the edges(0 is the first vertex):"<<endl;
	for(ll i=0;i<edges_no;i++){
		vector<ll> v;	ll a,b;
		cin>>a;	cin>>b; v.push_back(a);v.push_back(b);weights.push_back(1);
		edges.push_back(v);
	}

	if(!fileReadInput)
		cout<<"=========================="<<endl;

	Graph *G;
	G = new Graph(nodes,edges,weights);
    long long int s = nodes_no;
    long long int t = nodes_no + 1;

	auto start = high_resolution_clock::now();
	cout<<"STARTED!!!!!!"<<endl;
    bool flag = G->isBipartite();
	Ford_Fulkersen F(G,s,t);
	long long int maxflow = 0;
	while (true)
	{
		long long int flow = F.DFS(s,t);
		if  (flow == 0) break;
		else{ 
			F.augment(flow,s,t);
			maxflow += flow;
		}
	}
	cout<<"The maximum number of students that get jobs: "<<maxflow<<endl;
	cout<<"COMPLETE!!!!!!"<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken in microseconds: "<< duration.count() << endl;
    return 0;
}