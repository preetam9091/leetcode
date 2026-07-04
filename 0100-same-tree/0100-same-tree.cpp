class Solution {
public:
    void chk(TreeNode* p, TreeNode* q, int &c) {
        if (c == -1) return;

        if (p == NULL && q == NULL)
            return;

        if (p == NULL || q == NULL) {
            c = -1;
            return;
        }

        if (p->val != q->val) {
            c = -1;
            return;
        }

        chk(p->left, q->left, c);
        chk(p->right, q->right, c);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        int c = 0;
        chk(p, q, c);
        return c != -1;
    }
};