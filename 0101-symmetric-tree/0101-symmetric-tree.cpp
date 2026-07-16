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
    bool dfs(TreeNode* l, TreeNode* r){
        if((r && !l)|| (!r && l)){
            return false;
        }
        if(!r && !l){
            return true;
        }if(r->val!=l->val){
            return false;
        }
         return dfs(l->right, r->left) && dfs(l->left, r->right);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};