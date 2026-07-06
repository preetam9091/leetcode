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
    void solve(TreeNode* root, int max, int &n){
        if(root==nullptr) return;
        if(root->val>=max) {max = root->val; n++;}
        solve(root->left, max, n);
        solve(root->right, max, n);
    }
    int goodNodes(TreeNode* root) {
        int n = 0;
        solve(root, -10001, n);
        return n;
    }
};