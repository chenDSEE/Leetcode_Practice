/* backtracking */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (cnt != start && candidates[cnt - 1] == candidates[cnt]) {
                continue;
            }

            one.emplace_back(candidates[cnt]);
            DFS_travel(candidates, one, target - candidates[cnt], cnt + 1);
            one.pop_back();
        }
    }
};