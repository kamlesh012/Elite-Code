class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;

        // Calculate the prefix sum matrix
        vector<vector<int>> prefix_sum(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefix_sum[i][j] = matrix[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
        }

        // Iterate over all possible pairs of rows and columns
        for (int row1 = 1; row1 <= rows; ++row1) {
            for (int row2 = row1; row2 <= rows; ++row2) {
                for (int col1 = 1; col1 <= cols; ++col1) {
                    for (int col2 = col1; col2 <= cols; ++col2) {
                        // Calculate the sum of the submatrix using prefix sums
                        int submatrix_sum = prefix_sum[row2][col2] - prefix_sum[row1 - 1][col2] - prefix_sum[row2][col1 - 1] + prefix_sum[row1 - 1][col1 - 1];

                        // Check if the submatrix sum equals the target
                        if (submatrix_sum == target) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};