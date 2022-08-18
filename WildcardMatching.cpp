//Memoization
class Solution {
public:
    bool f(int ind1, int ind2, string &pattern, string &text,vector<vector<int>> &dp){
        if(ind1<0 and ind2<0) return true;
        if(ind1<0) return false;
        if(ind2<0){
            for(int i=0 ;i<=ind1; i++)
                if(pattern[i]!='*') return false;
            return true;
        }
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(pattern[ind1]=='*'){
            return dp[ind1][ind2] = f(ind1,ind2-1,pattern,text,dp) or f(ind1-1,ind2,pattern,text,dp) or f(ind1-1,ind2-1,pattern,text,dp);
        }
        if(pattern[ind1]=='?'){
            return dp[ind1][ind2] = f(ind1-1,ind2-1,pattern,text,dp);
        }
        return dp[ind1][ind2] = pattern[ind1]==text[ind2] ? f(ind1-1,ind2-1,pattern,text,dp) : false;
    }
    
    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return f(n-1,m-1,pattern,text,dp);
    }
};
//TC : O(N*M)
//SC : O(N*M) [DP array] + O(N*M) [Stack Space]

//Tabulation
class Solution2 {
public:
    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        
        vector<vector<bool>> dp(n+1, vector<bool> (m+1,false));
        dp[0][0] = true;
        int i = 1;
        for(;i<=n and pattern[i-1]=='*';i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = true;
            }
        }
        
        for(;i<=n; i++){
            for(int j=1; j<=m; j++){
                if(pattern[i-1]=='*') dp[i][j] = dp[i][j-1] or dp[i-1][j] or dp[i-1][j-1];
                else if(pattern[i-1]=='?') dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = pattern[i-1] == text[j-1] ? dp[i-1][j-1] : false;
            }
        }
        
        return dp[n][m];
    }
};
//TC : O(N*M)
//SC : O(N*M) [Dp array]

//Space Optimized
class Solution3 {
public:
    bool isAllStars(string &pattern, int ind){
        for(int i=0; i<=ind; i++){
            if(pattern[i]!='*') return false;
        }
        return true;
    }
    bool isMatch(string text, string pattern)
    {
        int n = pattern.size();
        int m = text.size();
        
        vector<bool> prev(m+1,false);
        vector<bool> cur(m+1,false);
        prev[0] = true;
        
        for(int i=1; i<=n; i++){
            cur[0] = isAllStars(pattern,i-1);
            for(int j=1; j<=m; j++){
                if(pattern[i-1]=='*') cur[j] = cur[j-1] or prev[j] or cur[j-1];
                else if(pattern[i-1]=='?') cur[j] = prev[j-1];
                else cur[j] = pattern[i-1] == text[j-1] ? prev[j-1] : false;
            }
            prev = cur;
        }
        
        return prev[m];
    }

};
//TC : O(N*M)
//SC : O(M)

