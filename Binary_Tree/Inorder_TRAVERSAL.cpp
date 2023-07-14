/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Recursive Solution
// TC: O(N)
// SC: O(N)
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Morris Traversal Solution
// TC: O(N)
// SC: O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.emplace_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    ans.emplace_back(curr->val);
                    curr=curr->right;
                    prev->right=NULL;
                }
            }
            
        }
        return ans;
    }
};