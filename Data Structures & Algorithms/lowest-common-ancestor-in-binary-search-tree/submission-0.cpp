/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool find_path(TreeNode* root,TreeNode* node,vector<TreeNode*>& path){

        if(root == NULL) return false ;
        path.push_back(root);

        if(root == node) return true;
        if(find_path(root->left,node,path) || find_path(root->right,node,path)){
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        vector<TreeNode*> pp;
        vector<TreeNode*> qq;
        find_path(root,p,pp);
        find_path(root,q,qq);
        
        int i = 0;
        while(i<pp.size() && i<qq.size() && (pp[i] == qq[i])){
            i++;
        }
        return pp[i-1];
    }
};