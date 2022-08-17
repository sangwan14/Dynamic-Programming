//Memoization
class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, string &str1, string &str2){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str1[i]==str2[j]) return dp[i][j] = f(i-1,j-1,str1,str2);
        return dp[i][j] = 1 + min(f(i-1,j-1,str1,str2), min(f(i-1,j,str1,str2), f(i,j-1,str1,str2)));
    }
    
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        dp.resize(n, vector<int> (m,-1));
        return f(n-1, m-1, str1, str2);
    }
};
//TC : O(N*M)
//SC : O(N*M) [Stack Space] + O(N*M) [DP array]

//Tabulation
class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        dp.resize(n+1, vector<int> (m+1));
        
        for(int i=0; i<=m; i++) dp[0][i] = i;
        for(int i=0; i<=n; i++) dp[i][0] = i;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        
        return dp[n][m];
    }
};
//TC : O(N*M)
//SC : O(N*M) [DP array]

//Space Optimization
class Solution3{
  int editDistance(string str1, string str2)
  {
      int n = str1.size();
      int m = str2.size();

      vector<int> prev(m+1);
      for(int i=0; i<=m; i++){
          prev[i] = i;
      }

      for(int i=1; i<=n; i++){
          vector<int> cur(m+1,0);
          cur[0] = i;
          for(int j=1; j<=m; j++){
              if(str1[i-1]==str2[j-1]){
                  cur[j] = prev[j-1];
              }
              else{
                  cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
              }
          }
               prev = cur;
      }

      return prev[m];
  }
};
//TC : O(N*M)
//SC : O(min(N,M))

//Space Optimization 2
class Solution4{
    public:
    int  minDistance(string str1, string str2)
    {
      int n = str1.size();
      int m = str2.size();

      vector<vector<int>> dp(2,vector<int> (m+1));
      for(int i=0; i<=m; i++){
          dp[1][i] = i;
      }

      for(int i=1; i<=n; i++){
          dp[!(i%2)][0] = i;
          for(int j=1; j<=m; j++){
              if(str1[i-1]==str2[j-1]){
                  dp[!(i%2)][j] = dp[i%2][j-1];
              }
              else{
                  dp[!(i%2)][j] = 1 + min(dp[i%2][j-1], min(dp[i%2][j], dp[!(i%2)][j-1]));
              }
          }
      }

      return dp[(n+1)%2][m];
    }
};
//TC : O(N*M)
//SC : O(min(N,M))
