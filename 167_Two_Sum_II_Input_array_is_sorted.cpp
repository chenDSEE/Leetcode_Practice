class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) {
            return vector<int> {-1, -1};
        }

        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                while (left < right && numbers[right] == numbers[--right]);

            } else if (sum < target) {
                while (left < right && numbers[left] == numbers[++left]);

            } else {
                return vector<int> {left + 1, right + 1};
            }
        }

        return vector<int> {-1, -1};
    }
};