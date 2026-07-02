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
    void count(TreeNode* root, int i, int& max){
        if(root==NULL) return;
        if(i>max){
            max = i;
        }
        count(root->left, i+1, max);
        count(root->right, i+1, max);
    }
    int maxDepth(TreeNode* root) {
        int max = 0;
        count(root, 1, max);
        return max;
    }
};