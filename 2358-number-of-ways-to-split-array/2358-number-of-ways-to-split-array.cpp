class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0, leftSum = 0;
        int count = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Traverse the array to split into two parts
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;

            // Check if left sum is greater than or equal to right sum
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
