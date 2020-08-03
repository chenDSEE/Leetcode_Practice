

/* DP Version (有点慢，你看看能不能优化一下) */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if (numRows <= 0) {
            return answer;
        }

        answer.emplace_back(vector<int> {1});
        for (int level = 2; level <= numRows; level++) {
            vector<int> row(level);
            row[0] = 1, row[row.size() - 1] = 1;
            for (int cnt = 1; cnt < row.size() - 1; cnt++) {
                row[cnt] = answer.back()[cnt - 1] + answer.back()[cnt];
            }
    
            answer.emplace_back(row);
        }

        return answer;
    }
};