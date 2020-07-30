// 尝试自顶向下的方式，每次把 pair 传递下去就好了 ？？
// 别傻了，这是不存在的方法 ！！！ 因为彻底偷完，并不是到了某一个分支的尽头就好了的
// 而是，整个树的所有分支都搜刮完毕 ！


/* DP Version (后续遍历，自底向上) */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        auto sum = sub_rob(root);
        return max(sum.first, sum.second);
    }

private:
    // first -> not rob; second -> rob
    pair<int, int> sub_rob(TreeNode *node) {
        if (node == nullptr) {
            return {0, 0};
        }

        // 后续遍历
        auto left = sub_rob(node->left);
        auto right = sub_rob(node->right);

        // handle this level
        int rob = node->val + left.second + right.second;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, not_rob};
    }
};