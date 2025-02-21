class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int sq = n * n;
        int count = 1;
        int left = 0, bottom = n - 1, top = 0, right = n - 1;
    
        while (count <= sq && left <= right && top <= bottom) {
            // Traverse from left to right
            for (int j = left; j <= right; j++)
                matrix[top][j] = count++;
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = count++;
            right--;

            // Traverse from right to left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    matrix[bottom][j] = count++;
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    matrix[i][left] = count++;
                left++;
            }
        }
        return matrix;
    }
};