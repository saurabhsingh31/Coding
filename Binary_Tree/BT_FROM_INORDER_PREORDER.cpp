//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int in[],int in_start,int in_end,int pre[],int pre_start,int pre_end,map<int,queue<int>> &pos)
        {
            if(pre_start>pre_end|| in_start>in_end)
            {
                return NULL;
            }
            int inroot=pos[pre[pre_start]].front();
            pos[pre[pre_start]].pop();
            int elem=inroot-in_start;
            Node* root=new Node(pre[pre_start]);
            root->left=solve(in,in_start,inroot-1,pre,pre_start+1,pre_start+elem,pos);
            root->right=solve(in,inroot+1,in_end,pre,pre_start+elem+1,pre_end,pos);
            return root;
            
        }
        
        Node* buildTree(int in[],int pre[], int n)
        {
            if(n==0)
                return NULL;
            map<int,queue<int>> pos;
            for(int i=0;i<n;i++)
            {
                pos[in[i]].push(i);
            }
            return solve(in,0,n-1,pre,0,n-1,pos);
        }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends