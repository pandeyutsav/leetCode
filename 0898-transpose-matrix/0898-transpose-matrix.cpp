class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns

        // Correct size of transposed matrix (n x m)
        vector<vector<int>> ans(n, vector<int>(m));

        // Transpose logic: swap rows and columns
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[j][i] = matrix[i][j]; // Swap row-column

        return ans;
    }
};