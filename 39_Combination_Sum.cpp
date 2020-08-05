/* DP 可以直接算总数，相当于 0-1 背包问题 */




/* backtracking - 剪枝加速 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return answer;
        }

        vector<int> one;
        sort(candidates.begin(), candidates.end());
        DFS_travel(candidates, one, target, 0);
        return answer;
    }

private:
    vector<vector<int>> answer;

    void DFS_travel(vector<int> &candidates, vector<int> &one, int target, int start) {
        if (target == 0) {
            answer.emplace_back(one);
            return ;
        }

        for (int cnt = start; cnt < candidates.size() && target - candidates[cnt] >= 0; cnt++) {
            one.emplace_back(candidates[cnt]);
            DFS_travel(candidates, one, target - candidates[cnt], cnt);
            one.pop_back();
        }
    }
};



/* backtracking */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return vector<vector<int>> {};
        }

        vector<int> one;
        sub_combinationSum(candidates, one, target, 0, 0);
        return answer;
    }

private:
    vector<vector<int>> answer;

    void sub_combinationSum(vector<int> &candidates, vector<int> &one, int target, int sum, int start)
    {
        if (sum > target) {
            return ;
        }

        if (sum == target) {
            answer.emplace_back(one);
            return ;
        }

        for (int cnt = start; cnt < candidates.size(); cnt++) {
            if (sum + candidates[cnt] <= target) {
                one.emplace_back(candidates[cnt]);

                sub_combinationSum(candidates, one, target, sum + candidates[cnt], cnt);

                one.pop_back();
            }
        }

        return ;
    }
};
