/* DP 可以直接算总数，相当于 0-1 背包问题 */



/* 优雅版本（not mine） */
// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }

};


/* backtracking - 剪枝加速 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return vector<vector<int>> {};
        }

        vector<int> one;
        sort(candidates.begin(), candidates.end());
        sub_combinationSum(candidates, one, target, 0, 0);
        return answer;
    }

private:
    vector<vector<int>> answer;

    void sub_combinationSum(vector<int> &candidates, vector<int> &one,
        int target, int sum, int start)
    {
        if (sum > target) {
            return ;
        }

        if (sum == target) {
            answer.emplace_back(one);
            return ;
        }

        for (int cnt = start; cnt < candidates.size(); cnt++) {
            if (sum + candidates[cnt] > target) {
                return ;
            }

            one.emplace_back(candidates[cnt]);
            sub_combinationSum(candidates, one, target, sum + candidates[cnt], cnt);
            one.pop_back();
        }

        return ;
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
