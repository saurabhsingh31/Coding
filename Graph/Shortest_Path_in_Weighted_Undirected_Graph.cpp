//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        vector<int> dist(n+1,INT_MAX);
        vector<pair<int,int>> adj[n+1];
        int src=1;
        int dest=n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src});
        dist[src]=0;
        parent[src]=1;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        while(!q.empty()){
            auto top=q.top();
            q.pop();
            int node=top.second;
            int wt=top.first;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(dist[adjnode]>edw+wt){
                    dist[adjnode]=edw+wt;
                    parent[adjnode]=node;
                    q.push({dist[adjnode],adjnode});
                }
            }
            
        }
        
        if(dist[dest]==INT_MAX){
            return {-1};
        }
        vector<int> ans;
        int node=dest;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
            
        }
        ans.push_back(src);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends