class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int m=matrix.size();
        int n = matrix[0].size();
        int top=0,right=n-1,left=0,bottom=m-1;
        while(left<=right&&top<=bottom)
        {
        for(int j=top;j<=right;j++)
        ans.push_back(matrix[top][j]);
        top++;
        for(int i=top;i<=bottom;i++)
        ans.push_back(matrix[i][right]);
        right--;
        if(top<=bottom)
        for(int j=right;j>=left;j--)
        ans.push_back(matrix[bottom][j]);
        bottom--;
        if(left<=right)
        for(int i=bottom;i>=top;i--)
        ans.push_back(matrix[i][left]);
        left++;
        }
        return ans;
    }
};