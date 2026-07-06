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
    void solve(TreeNode* root, priority_queue<int> &p){
        if(root==nullptr) return;
        p.push(root->val);
        solve(root->left, p);
        solve(root->right, p);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> p;
        solve(root, p);
        while(p.size()>k){
            p.pop();
        }
        return p.top();
    }
};