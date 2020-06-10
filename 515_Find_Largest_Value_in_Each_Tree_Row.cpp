/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* My BFS version */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<pair<TreeNode *, int>> wait_queue;    // node -- level
        vector<int> answer;

        if (root)
            wait_queue.push({root, 0});

        while (!wait_queue.empty()) {
            TreeNode *curr_node = wait_queue.front().first;
            int curr_level = wait_queue.front().second;
            wait_queue.pop();

            if (answer.size() <= curr_level)    // pay attention for this line !
                answer.push_back(INT_MIN);

            if (curr_node->val > answer[curr_level])
                answer[curr_level] = curr_node->val;

            if (curr_node->left)
                wait_queue.push({curr_node->left, curr_level + 1});
            if (curr_node->right)
                wait_queue.push({curr_node->right, curr_level + 1});

        }   // end of while

        return answer;
    }
};

/* another BFS version */
