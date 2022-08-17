//Memoization
class Solution{
    public:
    const int mod = 1e9+7;
    int solve(int ind1, int ind2, string &t, string &s, vector<vector<int>> &dp){
        if(ind2<0) return 1;
        if(ind1<0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(t[ind1]==s[ind2]){
            return dp[ind1][ind2] = (solve(ind1-1,ind2,t,s,dp) + solve(ind1-1,ind2-1,t,s,dp))%mod;
        }
        return dp[ind1][ind2] = solve(ind1-1,ind2,t,s,dp)%mod;
    }

    int subsequenceCounting(string &t, string &s, int lt, int ls) {
        vector<vector<int>> m(2, vector<int> (ls+1, 0));

        for(int i=1; i<=lt; i++){
            m[i%2][0] = 1;
            for(int j=1; j<=ls; j++){
                m[!(i%2)][j] = (t[i-1]==s[j-1] ? m[i%2][j] + m[i%2][j-1] : m[i%2][j])%mod;
            }
        }

        return m[(lt+1)%2][ls];
    } 
};
//TC : O(N*M)
//SC : O(N*M) [DP array] + O(N) [Recursion Stack Space]

//Tabulation
class Solution2{
    public:
    const int mod = 1e9+7;

    int subsequenceCounting(string &t, string &s, int lt, int ls) {
        vector<vector<int>> dp(lt+1, vector<int> (ls+1, 0));
        dp[0][0] = 1;

        for(int i=1; i<=lt; i++){
            dp[i][0] = 1;
            for(int j=1; j<=ls; j++){
                dp[i][j] = (t[i-1]==s[j-1] ? dp[i-1][j] + dp[i-1][j-1] : dp[i-1][j])%mod;
            }
        }

        return dp[lt][ls];
    } 
};
//TC : O(N*M)
//SC : O(min(N,M))

//Space Optimized
class Solution3{
    public:
    const int mod = 1e9+7;

    int subsequenceCounting(string &t, string &s, int lt, int ls) {
        vector<vector<int>> m(2, vector<int> (ls+1, 0));

        for(int i=1; i<=lt; i++){
            m[i%2][0] = 1;
            for(int j=1; j<=ls; j++){
                m[!(i%2)][j] = (t[i-1]==s[j-1] ? m[i%2][j] + m[i%2][j-1] : m[i%2][j])%mod;
            }
        }

        return m[(lt+1)%2][ls];
    } 
};
//TC : O(N*M)
//SC : O(min(N,M))
