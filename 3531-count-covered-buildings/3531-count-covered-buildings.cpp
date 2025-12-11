class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, int> xmap;
        map<int, int> ymap;
        int m = buildings.size(), x, y;
        for(int i = 0;i<m;i++){
            x = buildings[i][0];
            y = buildings[i][1];
            xmap[x]++;
            ymap[y]++;
        }

        sort(buildings.begin(), buildings.end());
        int ans = 0;
        map<int, int> currx;
        map<int, int> curry;
        for(int i = 0;i<m;i++){
            x = buildings[i][0];
            y = buildings[i][1];
            if(currx[x] > 0 and currx[x] < xmap[x] - 1 and curry[y] > 0 and curry[y] < ymap[y] - 1)
                ans++;
            currx[x]++;
            curry[y]++;
        }
        return ans;
    }
};