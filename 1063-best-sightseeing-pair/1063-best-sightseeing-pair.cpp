class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxPrefix = values[0] + 0; // Maximum prefix seen so far
        int maxi = INT_MIN;           // Stores the maximum score

        for (int j = 1; j < values.size(); j++) {
            // Calculate the score for the current pair
            maxi = max(maxi, maxPrefix + values[j] - j);

            // Update maxPrefix for the next iteration
            maxPrefix = max(maxPrefix, values[j] + j);
        }

        return maxi;
    }
};
