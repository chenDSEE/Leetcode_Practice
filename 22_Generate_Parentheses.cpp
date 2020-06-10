/* DFS */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        helper(answer, "", 0, 0, n);
        return answer;
    }

    void helper(vector<string> &answer, string tmp, int left, int right, const int n) {
        if (tmp.size() >= 2 * n) {
            answer.emplace_back(tmp);
            return ;
        }

        if (left < n) {
            helper(answer, tmp + '(', left + 1, right, n);
        }
        if (right < left) {
            helper(answer, tmp + ')', left, right + 1, n);
        }
    }
};

/* BFS */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<pair<string, int>> wait_queue;    // inter_string -- left_cnt
        vector<string> answer;

        wait_queue.push({"", 0});
        while (!wait_queue.empty()) {
            string curr = wait_queue.front().first;
            int left = wait_queue.front().second;
            int right = curr.size() - left;
            wait_queue.pop();

            if (curr.size() >= 2 * n) {
                answer.emplace_back(curr);

            } 
            if (left < n) {
                wait_queue.push({curr + '(', left + 1});
            }
            if (right < n && right < left) {
                wait_queue.push({curr + ')', left});
            }
        }   // end of while

        return answer;
    }
};