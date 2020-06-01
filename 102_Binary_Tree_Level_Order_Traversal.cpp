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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        travel_tree(answer, root, 0);
        return answer;
    }

    void travel_tree(vector<vector<int>> &answer, TreeNode *root, int level) {
        if (root) {
            if (answer.size() < level + 1)
                answer.push_back(vector<int> {});

            answer[level].push_back(root->val);
            travel_tree(answer, root->left, level + 1);
            travel_tree(answer, root->right, level + 1);
        }
    }
};

/* 学完 BFS、DFS 之后回来再刷一次 */