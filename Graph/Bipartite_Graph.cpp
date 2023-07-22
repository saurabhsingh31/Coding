//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int node, int col, vector<int> graph[], vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node]=col;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:graph[curr]){
                if(color[it]==-1){
                    color[it]=!color[curr];
                    q.push(it);
                }
                else{
                    if(color[it]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,0,adj,color)){
                    return false;
                }
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends