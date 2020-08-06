/* Bit operate */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
		for (int each : nums) {
			val ^= each;
		}
		
		return val;
    }
};

/* Hash Version */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> record;
        for (int val : nums) {
            if (record.count(val) == 0)
                record.insert(val);
            else
                record.erase(val);
        }

        return *(record.begin());
    }
};