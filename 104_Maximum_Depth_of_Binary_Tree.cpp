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
    int maxDepth(TreeNode* root) {
        int max_level = 0;
        helper(root, max_level, 1);
        return max_level;
    }

    void helper(TreeNode *root, int &max_level, int cur_level) {
        if (root) {
            helper(root->left, max_level, cur_level + 1);
            helper(root->right, max_level, cur_level + 1);

        } else {
            if (max_level < cur_level - 1) {
                max_level = cur_level - 1;          
            }
        }
    }

};