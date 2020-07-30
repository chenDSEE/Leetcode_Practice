class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<int> queen_pos;
        solve_n_queens_split(answer, queen_pos, n);        
        return answer;
    }

    void solve_n_queens_split(vector<vector<string>> &answer, vector<int> &queen_pos, int n) {
        if (queen_pos.size() >= n) {
            draw_queen(answer, queen_pos);
            return ;
        }

        int y = queen_pos.size() - 1;
        for (int x = 0; x < n; x++) {
            if (column.count(x) == 0 && left.count(x + y) == 0 && right.count(y - x) == 0) {
                queen_pos.emplace_back(x);
                column.insert(x);
                left.insert(x + y);
                right.insert(y - x);

                solve_n_queens_split(answer, queen_pos, n);

                queen_pos.pop_back();
                column.erase(x);
                left.erase(x + y);
                right.erase(y - x);
            }
        }

        return ;
    }

private:
    unordered_set<int> column;
    unordered_set<int> left;    // y + x
    unordered_set<int> right;   // y - x
    
    void draw_queen(vector<vector<string>> &answer, vector<int> &queen_pos) {
        answer.emplace_back(vector<string> {});
        string tmp(queen_pos.size(), '.');
        for (int pos : queen_pos) {
            tmp[pos] = 'Q';
            answer.back().emplace_back(tmp);
            tmp[pos] = '.';
        }

    }
};


// better version
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queen_pos;
        DFS_solve_queen(queen_pos, n);

        return answer;
    }

private:
    unordered_set<int> column;
    unordered_set<int> left;
    unordered_set<int> right;
    vector<vector<string>> answer; 

    void DFS_solve_queen(vector<int> &queen_pos, const int n) {
        if (queen_pos.size() == n) {
            answer.emplace_back(draw_board(queen_pos));
            return ;
        }

        int level = queen_pos.size();
        for (int pos = 0; pos < n; pos++) {
            if (column.count(pos) == 0 && left.count(pos + level) == 0 && right.count(level - pos) == 0) {
                queen_pos.emplace_back(pos);
                column.insert(pos);
                left.insert(pos + level);
                right.insert(level - pos);

                DFS_solve_queen(queen_pos, n);

                // revert
                queen_pos.pop_back();
                column.erase(pos);
                left.erase(pos + level);
                right.erase(level - pos);
            }
        }

        return ;
    }

    vector<string> draw_board(vector<int> &queen_pos) {
        vector<string> buf;
        string one(queen_pos.size(), '.');
        for (int cnt = 0; cnt < queen_pos.size(); cnt++) {
            one[queen_pos[cnt]] = 'Q';
            buf.emplace_back(one);
            one[queen_pos[cnt]] = '.';
        }

        return buf;
    }
};

/* Bit mask Version(my) */
class Solution {
private:
    int size = 0;
    vector<vector<string>> answer;

public:
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<uint32_t> record;
        sub_solve(record, 0, 0, 0);
        return answer;
    }

private:
    void sub_solve(vector<uint32_t> &record, uint32_t left, uint32_t mid, uint32_t right) {
        if (record.size() == size) {
            draw_queen(record);
            return ;
        }

        int level = record.size();
        uint32_t not_use_pos = (~(left | mid | right)) & ((1 << size) - 1);
        while (not_use_pos != 0) {
            uint32_t curr_pos = not_use_pos & (-not_use_pos);
            record.emplace_back(curr_pos);

            sub_solve(record, (left | curr_pos) << 1, mid | curr_pos, (right | curr_pos) >> 1);

            record.pop_back();
            not_use_pos = not_use_pos & (not_use_pos - 1);
        }

        return ;
    }

    void draw_queen(vector<uint32_t> &record) {
        string line(size, '.');
        vector<string> one;
        for (uint32_t pos : record) {
            int index = 0;
            while (pos) {
                index++;
                pos >>= 1;
            }
            line[size - index] = 'Q';
            one.emplace_back(line);
            line[size - index] = '.';
        }        

        answer.emplace_back(one);
    }
};


// bit mask version(not my version !!!)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n < 1) return {};
        size = n;
        mask = (1 << n) - 1;

        vector<int> firstSol(n, 0);
        BackTrack(0, 0, 0, 0, firstSol);

        return GenRes();
    }

private:
    void BackTrack(int row, int left, int down, int right, vector<int> &curSol) {
        if (row == size) {
            binRes.push_back(curSol);
        } else {
            int bitmap = mask & ~(left | down | right);
            while (bitmap) {
                int pick = -bitmap & bitmap;
                curSol[row] = pick;
                BackTrack(row + 1, (pick | left) << 1, pick | down, (pick | right) >> 1, curSol);
                bitmap ^= pick;
            }
        }
    }

    vector<vector<string>> GenRes() {
        vector<vector<string>> res(binRes.size(), vector<string>(size, string(size, '.')));
        for (int i = 0; i < binRes.size(); ++i) {
            for (int j = 0; j < size; ++j) {
                int binIdx = binRes[i][j];
                int count = 0;
                while (binIdx) {
                    binIdx >>= 1;
                    ++count;
                }
                res[i][j][size - count] = 'Q';
            }
        }
        return res;
    }

    int size, mask;
    vector<vector<int>> binRes;
};

