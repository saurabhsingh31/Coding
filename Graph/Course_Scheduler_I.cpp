//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
			for(auto it:prerequisites){
				adj[it.first].push_back(it.second);
			}
	    vector<int> ans;
	    vector<int> indegree(N,0);
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int front=q.front();
	        ans.push_back(front);
	        q.pop();
	        for(auto it:adj[front]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	        
	    }
	    if(ans.size()==N){
	        return true;
	    }
	    return false;
    
    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends