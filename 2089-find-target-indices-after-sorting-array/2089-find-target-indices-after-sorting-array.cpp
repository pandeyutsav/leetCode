class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int s=0, r=0;
        for(int x: nums){
            s+=(x<target);
            r+=(x==target);
        }
        iota(nums.begin(), nums.begin()+r, s);
        nums.resize(r);
        return nums;
    }
};