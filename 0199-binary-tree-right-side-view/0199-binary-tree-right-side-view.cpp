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
    void solve(TreeNode* root, vector<int> &res, int &max, int i){
        if(root==nullptr) return;
        if(i>max){ max=i;
        res.push_back(root->val);}
        solve(root->right, res, max, i+1);
        solve(root->left, res, max, i+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int max = -1;
        solve(root, res, max, 0);
        return res;
    }
};