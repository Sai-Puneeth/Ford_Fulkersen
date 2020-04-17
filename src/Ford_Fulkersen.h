#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

class Ford_Fulkersen{
    public :
        vector<long long int> parent;
        Graph *Gr ;

        Ford_Fulkersen(Graph *G,long long int s,long long int t){
            Gr = G;
            for (long long int i=0;i<Gr->nodes.size();i++) parent.push_back(0);
        }
        long long int DFS(long long int s,long long int t);
        void augment(long long int flow,long long int s,long long int t);
    };
        //DFS to find flow and store path in the form of parent vector
    long long int Ford_Fulkersen :: DFS(long long int s,long long int t){
        int flow = 0;
        for (int i=0;i<Gr->nodes.size();i++) parent[i] = -1;
        stack<int> dfs_stack;
        stack<int> minCapacity;
        parent[s] = -1;
        dfs_stack.push(s);
        minCapacity.push(99999);
        while (!dfs_stack.empty())
        {
            int top = dfs_stack.top();
            int mt = minCapacity.top();
            dfs_stack.pop();
            minCapacity.pop();
            if (top == t)
            {
                flow = mt;
                break;
            }
            for (int i=0;i<Gr->nodes.size();i++)
            {
                if (Gr->G[top][i] > 0 && parent[i] == -1)
                {
                    dfs_stack.push(i);
                    minCapacity.push(min(mt,int(Gr->G[top][i])));
                    parent[i] = top;
                }
            }
        }
        return flow;
    }


    // augmenting the graph after finding a path
    void Ford_Fulkersen :: augment(long long int flow,long long int s,long long int t){
        if (flow > 0){
            int currNode = t;
            while (currNode != s){
                Gr->G[parent[currNode]][currNode] -= flow;
                Gr->G[currNode][parent[currNode]] += flow;
                currNode = parent[currNode];
            }
        }
    }
