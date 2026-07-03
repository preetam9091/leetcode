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
    int check(TreeNode* root, bool& chk){
        if(!root){
            return 0;
        }
        int left = check(root->left, chk);
        int right = check(root->right, chk);
        if(left>right+1 || right>left+1){
            if(chk) chk = false; 
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool chk = true;
        check(root, chk);
        return chk;
    }
};