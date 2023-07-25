//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> s;
        vector<int> dist(V,INT_MAX);
        s.insert({0,S});
        dist[S]=0;
        while(!s.empty()){
            auto top=*(s.begin());
            s.erase(top);
            int node=top.second;
            int dis=top.first;
            for(auto it:adj[node]){
                int adjnode=it[0];
                int wt=it[1];
                if(dist[adjnode]>dis+wt){
                    if(dist[adjnode]!=INT_MAX){
                        s.erase({dist[adjnode],adjnode});
                    }
                    
                    dist[adjnode]=dis+wt;
                    s.insert({dist[adjnode],adjnode});
                    
                    
                }
                
            }
        }
        return dist;

    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends