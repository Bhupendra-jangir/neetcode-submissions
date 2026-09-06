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
    int f(TreeNode* root){
        if(root==NULL) return 0;
        int lh = f(root->left);
        int rh = f(root->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int l = f(root->left);
        int r = f(root->right);
        if(abs(l-r)>1) return false;
        bool lf = true,rt = true;
        if(root->left) lf = isBalanced(root->left) ;
        if(root->right) rt = isBalanced(root->right);
        return (lf && rt);
    }
};
