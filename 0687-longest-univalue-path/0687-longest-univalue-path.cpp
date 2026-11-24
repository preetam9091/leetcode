class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* r) {
        if (!r) return 0;

        int l = dfs(r->left);
        int h = dfs(r->right);

        int a = 0, b = 0;

        if (r->left && r->left->val == r->val)
            a = l + 1;

        if (r->right && r->right->val == r->val)
            b = h + 1;

        ans = max(ans, a + b);

        return max(a, b);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};