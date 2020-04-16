#include <bits/stdc++.h>
using namespace std;

class Ford_Fulkersen{
    public :
        long long int Ford_Fulkerson(vector<vector<long long int>> *G,long long int s,long long int t){
            int maxflow = 0;
            while (true)
            {
                int flow = DFS(G);
                if  (flow == 0) break;
                else{ 
                    maxflow += flow; 
                }
            }
            return flow;
        }

}
