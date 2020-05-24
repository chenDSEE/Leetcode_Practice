class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> max;
        vector<int> answer;

        if (k < 0 || nums.empty())
            return answer;

        for (int i = 0; i < nums.size(); i++) {
            while (!max.empty() && nums[i] > nums[max.back()]) {  // 只要没挖空，我就继续挖
                max.pop_back();
            }

            max.push_back(i);

            if (i - max.front() >= k)
                max.pop_front();

            if (i + 1 >= k)
                answer.push_back(nums[max.front()]);
        }

        return answer;
    }
};