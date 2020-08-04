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

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};


/* backtracking(不够优雅！！！) */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> one;
        sub_combinationSum(candidates, one, target, 0, 0);
        
        return answer;
    }

private:
    vector<vector<int>> answer;

    void sub_combinationSum(vector<int> &candidates, vector<int> &one, int target, int sum, int start) {
        if (sum == target) {
            answer.emplace_back(one);
            return ;
        }
        if (start >= candidates.size()) {
            return ;
        }


        int cnt = start;
        while (cnt < candidates.size()) {
            if (sum + candidates[cnt] > target) {
                return ;
            }

            one.emplace_back(candidates[cnt]);
            sub_combinationSum(candidates, one, target, sum + candidates[cnt], ++cnt);
            one.pop_back();

            // stop at [2, 2, 2 | 5], next loop, cnt is candidates[cnt] = 5
            while (cnt < candidates.size() && candidates[cnt - 1] == candidates[cnt]) {
                cnt++;
            }
        }
    }
};