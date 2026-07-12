using int2=pair<int, int>;
constexpr int N=1e5;
int2 arrIdx[N];
class Solution {
public:
    static vector<int> arrayRankTransform(vector<int>& arr) {
        const int n=arr.size();
        if (n==0) return {};
        
        for(int i=0; int x: arr){
            arrIdx[i]={x, i};
            i++;
        }
        sort(arrIdx, arrIdx+n);
        vector<int> ans(n);
        int prev=INT_MIN, curr=0;
        for(int j=0; j<n; j++){
            auto& [x, i]=arrIdx[j];
            if (x>prev) curr++;
            ans[i]=curr;
            prev=x;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();