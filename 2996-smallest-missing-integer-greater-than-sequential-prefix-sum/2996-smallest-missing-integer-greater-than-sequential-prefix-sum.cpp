class Solution {
public:
    int missingInteger(vector<int>& A) {
        int res = A[0];
        uint64_t vis = 0;
        bool seq = 1;

        vis |= 1ULL << A[0];

        for (int i = 1; i < A.size(); i++) {
            seq &= !(A[i] - A[i - 1] - 1);
            res += A[i] * seq;
            vis |= 1ULL << A[i];
        }

        if (res >= 64)
            return res;

        return __builtin_ctzll((~vis) & (~0ULL << res));
    }
};