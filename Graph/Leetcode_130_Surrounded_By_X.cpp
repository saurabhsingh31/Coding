class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        int delrow[4]={1,-1,0,0};
        int delcol[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                cout<<"here";
                dfs(n-1,i,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};