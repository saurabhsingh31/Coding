//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int delrow[4]={1,-1,0,0};
        int delcol[4]={0,0,-1,1};
        while(!q.empty()){
            auto front=q.front();
            int t=front.second;
            time=max(t,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=front.first.first+delrow[i];
                int ncol=front.first.second+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends