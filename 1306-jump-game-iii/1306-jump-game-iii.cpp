constexpr int N=5e4;
int q[N], front=0, back=0;
bool vis[N];
class Solution {
public:
    static bool canReach(vector<int>& arr, int start) {
        const int n=arr.size();
        front=back=0;// reset q
        q[back++]=start;
        vis[start]=1;
        while(front<back){
            const int i=q[front++];
            const int x=arr[i], l=i-x, r=i+x;
            if (x==0){
                memset(vis, 0, n);// reset for next testcase
                return 1;
            }
            if (l>=0 && !vis[l]) q[back++]=l, vis[l]=1;
            if (r<n  && !vis[r]) q[back++]=r, vis[r]=1;
        }
        memset(vis, 0, n);// reset vis
        return 0;
    }
};