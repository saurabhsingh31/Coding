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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *temp=root;
        if(root==NULL){
            TreeNode *root=new TreeNode(val);
            return root;
        }
        while(temp){
            if(temp->val>val){
                if(temp->left)
                    temp=temp->left;
                else{
                    break;
                }
            }
            else{
                if(temp->right)
                    temp=temp->right;
                else{
                    break;
                }
            }
        }
        TreeNode *node=new TreeNode(val);
        if(temp->val>val){
            temp->left=node;
        }
        else{
            temp->right=node;
        }
        return root;
        
    }
};