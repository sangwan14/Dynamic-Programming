//Space Optimized
int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(2, vector<int> (m+1, 0));
    int res = -1e9;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[!(i % 2)][j + 1] = str1[i] == str2[j] ? dp[i % 2][j] + 1 : 0;
            res = max(res,dp[!(i % 2)][j + 1]);
        }
    }

    return res;
}
//TC : O(N*M)
//SC : O(min(N*M))
