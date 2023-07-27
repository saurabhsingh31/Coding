//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0){
            return -1;
        }
        int steps=0;
        vector<vector<int>> dist(N,vector<int>(M,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        int delrow[4]={1,-1,0,0};
        int delcol[4]={0,0,-1,1};
        q.push({0,{0,0}});
        dist[0][0]=0;
        int nrow,ncol;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int row=front.second.first;
            int col=front.second.second;
            int dis=front.first;
            if(row==X && col==Y){
                return dis;
            }
            for(int i=0;i<4;i++){
                nrow=row+delrow[i];
                ncol=col+delcol[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && A[nrow][ncol]==1){
                    if(dist[nrow][ncol]>dis+1){
                        dist[nrow][ncol]=dis+1;
                        q.push({dis+1,{nrow,ncol}});
                        
                    }
                }
            }
        }

        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends