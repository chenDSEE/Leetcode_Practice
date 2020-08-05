/* 直接旋转替换 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size() - 1;
        
        for (int row = 0; row <= (size >> 1); row++) {
            for (int col = row; col < size - row; col++) {
                swap(matrix[row][col], matrix[col][size - row]);
                swap(matrix[row][col], matrix[size - row][size - col]);
                swap(matrix[row][col], matrix[size - col][row]);
            }
        }

        return ;
    }
};


/* 对角线镜像，上下翻转（not mine） */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<i; j++) swap(matrix[i][j], matrix[j][i]);
        
        for (auto& row: matrix) reverse(row.begin(), row.end());
    }
};
