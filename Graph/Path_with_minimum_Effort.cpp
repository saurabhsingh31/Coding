//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        dist[0][0]=0;
        q.push({0,{0,0}});
        
        int delrow[4]={1,-1,0,0};
        int delcol[4]={0,0,-1,1};
        
        while(!q.empty()){
            auto front =q.top();
            int dis=front.first;
            int row=front.second.first;
            int col=front.second.second;
            q.pop();
            
            if(row==n-1 && col==m-1){
                return dis;
            }
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int neweffort=max(dis,abs(heights[nrow][ncol]-heights[row][col]));
                    if(dist[nrow][ncol]>neweffort){
                        dist[nrow][ncol]=neweffort;
                        q.push({neweffort,{nrow,ncol}});
                    }
                }
            }
            
        }
        return 0;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends