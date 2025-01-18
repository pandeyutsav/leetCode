class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0,rightMax=0,water=0,index=0;
        int maxht=height[0];
        for(int i=1;i<n;i++)
        {
            if(height[i]>maxht)
            {
                maxht=height[i];
                index=i;
            }
        }
        for(int i=0;i<index;i++)
        {
            if(leftMax>height[i])
                water+=(leftMax-height[i]);
            else
                leftMax=height[i];
        }
        for(int i=n-1;i>index;i--)
        {
            if(rightMax>height[i])
                water+=(rightMax-height[i]);
            else 
                rightMax=height[i];
        }
        return water;
    }
};