

/* 先序遍历，完全构造新树 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }

        TreeNode *left = mergeTrees(t1 == nullptr ? nullptr : t1->left, t2 == nullptr ? nullptr : t2->left);
        TreeNode *right = mergeTrees(t1 == nullptr ? nullptr : t1->right, t2 == nullptr ? nullptr : t2->right);

        TreeNode *curr = new TreeNode((t1 == nullptr ? 0 : t1->val) + (t2 == nullptr ? 0 : t2->val));
        curr->left = left;
        curr->right = right;
        return curr;
    }
};