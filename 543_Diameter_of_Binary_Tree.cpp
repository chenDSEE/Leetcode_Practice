/* 自底向上遍历 */
/**
 * 每个节点只上传自己的 sub-tree 中最长的子树，然后每个节点在去计算
 * 自己节点上的 sub-tree 可以组合出来的最长路径
 * 
 * 遍历完毕整棵树之后，再来找整棵树最长的路径
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longest_sub_tree(root);

        int max_val = 0;
        for (auto val : node_sum) {
            max_val = max(max_val, val);
        }

        return max_val;
    }

private:
    vector<int> node_sum;
    int longest_sub_tree(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int left = longest_sub_tree(node->left);
        int right = longest_sub_tree(node->right);

        node_sum.emplace_back(left + right);
        return max(left, right) + 1;
    } 
};
