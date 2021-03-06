/* DFS */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<bool> used(nums.size(), false);
        vector<int> one;

        helper(answer, nums, used, one);
        return answer;
    }

    void helper(vector<vector<int>> &answer, const vector<int> &nums, 
                vector<bool> &used, vector<int> &one) 
    {
        if (one.size() >= nums.size()) {
            answer.push_back(one);
            return ;
        }

        for (int index = 0; index < nums.size(); index++) {
            if (used[index] == false) {
                used[index] = true;
                one.push_back(nums[index]);

                helper(answer, nums, used, one);

                used[index] = false;
                one.pop_back();
            }
        }
    }
};

/* better version(not a right order) */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;

        helper(answer, nums, 0);
        return answer;
    }

    void helper(vector<vector<int>> &answer, vector<int> &nums, int curr_used) 
    {
        if (curr_used == nums.size()) {
            answer.push_back(nums);
            return ;
        }

        for (int index = curr_used; index < nums.size(); index++) {
            swap(nums[index], nums[curr_used]);     // 将 本次将使用的坑位 跟 本次要尝试的数字 进行交换(本次使用的坑位上的数字一定要换走，因为这个数字是本次没有被使用的，下次可能被使用啊)
            helper(answer, nums, curr_used + 1);    // 已经使用的边界右移，
            swap(nums[index], nums[curr_used]);     // 将 本次将使用的坑位 跟 本次要尝试的数字 进行交换（还原，准备迭代 本次要尝试的数字）
        }

    }
};

/* BFS */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        queue<pair<vector<int>, unordered_set<int>>> wait_queue; // inter_vector -> is_used

        if (nums.size() > 0)
            wait_queue.push({vector<int> {}, unordered_set<int> {}});
        
        while (!wait_queue.empty()) {
            vector<int> curr_vec = wait_queue.front().first;
            unordered_set<int> curr_set = wait_queue.front().second;
            wait_queue.pop();

            if (curr_vec.size() == nums.size()) {
                answer.emplace_back(curr_vec);
                continue;
            }
            
            for (int check : nums) {
                if (curr_set.count(check) == 0) {
                    curr_vec.emplace_back(check);
                    curr_set.insert(check);

                    wait_queue.push({curr_vec, curr_set});

                    curr_vec.pop_back();
                    curr_set.erase(check);
                }
            }
        }   // end of while

        return answer;
    }
};

/* BFS better version */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        queue<pair<vector<int>, int>> wait_queue; // inter_answer -> curr_used

        if (nums.size() > 0)
            wait_queue.push({nums, 0});

        while (!wait_queue.empty()) {
            vector<int> curr_vec = wait_queue.front().first;
            int curr_use = wait_queue.front().second;
            wait_queue.pop();

            if (curr_use == nums.size() - 1) {
                answer.emplace_back(curr_vec);
                continue;
            }

            for (int check = curr_use; check < nums.size(); check++) {
                std::swap(curr_vec[check], curr_vec[curr_use]);
                wait_queue.push({curr_vec, curr_use + 1});
                std::swap(curr_vec[check], curr_vec[curr_use]);
            }


        }   // end of while

        return answer;
    }
};
