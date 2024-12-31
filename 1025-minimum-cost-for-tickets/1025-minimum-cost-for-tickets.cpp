class Solution {
public:
    vector<int> dp; 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.assign(n, -1);
        function<int(int)> f=[&](int i) mutable
        {
            if (i>=n) return 0;
            if (dp[i]!=-1) return dp[i];
            int ans=INT_MAX;
            int j=i+1;
            int d=days[i];
            
            ans=min(ans, f(j)+costs[0]);
            j=lower_bound(days.begin()+j, days.begin()+min(j+6, n), d+7)-days.begin();
            ans=min(ans, f(j)+costs[1]);
            j=lower_bound(days.begin()+j, days.begin()+min(j+23, n), d+30)-days.begin();
            ans=min(ans, f(j)+costs[2]);            
            return dp[i]=ans;   
        };
        return f(0); 
    }
};