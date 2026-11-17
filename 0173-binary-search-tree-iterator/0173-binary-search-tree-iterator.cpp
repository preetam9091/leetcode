class BSTIterator {
    stack<TreeNode*> st;

    void push(TreeNode* r) {
        while (r) {
            st.push(r);
            r = r->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        push(root);
    }

    int next() {
        auto r = st.top();
        st.pop();
        push(r->right);
        return r->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};