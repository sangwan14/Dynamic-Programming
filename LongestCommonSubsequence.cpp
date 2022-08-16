//Space Optimized
class Solution {
public:
    int lcs(string &a, string &b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(2, vector<int> (m+1,0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dp[!(i % 2)][j + 1] = a[i] == b[j] ? dp[i % 2][j] + 1 : max(dp[i % 2][j + 1], dp[!(i % 2)][j]);
        return dp[n % 2][m];
    }
};
//TC : O(N*M)
//SC : O(min(N,M))
