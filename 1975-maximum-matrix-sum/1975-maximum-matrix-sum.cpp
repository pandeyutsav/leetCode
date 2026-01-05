class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg = 0, min = INT_MAX;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                int val = abs(matrix[i][j]);
                if(matrix[i][j] < 0) neg++; 
                if(val < min) min = val;
                sum += val;
            }
        }
        return (neg & 1) == 0 ? sum : sum - 2 * min;
    }
};