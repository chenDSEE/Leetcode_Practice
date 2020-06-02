/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 这个跟最大深度是不一样的！你仔细看深度的定义，[1] = 1, [1,2,null,3] = 3 ! 这两个 case 很坑的！
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        int right = minDepth(root->right);
        int left = minDepth(root->left);

        if (!root->left || !root->right)
            return left + right + 1;
        
        return std::min(right, left) + 1;
    }
};