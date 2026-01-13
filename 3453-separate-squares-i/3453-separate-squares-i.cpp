class Solution {
public:
    bool check(vector<vector<int>>& squares , double mid , double total) {
        double belowArea = 0;
        for (auto& square : squares) {
            double y = square[1];
            double l = square[2];

            double belowY = y;
            double topY = y + l;

            if (mid >= topY) belowArea += l * l;
            else if (mid > belowY) belowArea += (mid - belowY) * l;
        }

        return belowArea >= (total / 2.0);
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = INT_MAX;
        double h = INT_MIN;
        double total = 0.00000;

        for (auto& square : squares) {
            double x = square[0];
            double y = square[1];
            double len = square[2];

            total += len * len;

            l = min(l , y);
            h = max(h , y + len);
        }

        double yCoord = 0.00000;
        while(h - l > 1e-5) {
            double mid = l + (h - l) / 2;
            yCoord = mid;

            if (check(squares , mid , total)) h = mid;
            else l = mid;
        }
        return yCoord;
    }
};