//Space Optimized
class Solution{
  int minInsertion(string &str)
  {
      int len = str.size();
      string rev = string(str.rbegin(),str.rend());

      int dp[2][len+1];
      for(int i=0;i<=1;i++){
          for(int j=0;j<len;j++){
              if(i==0 || j==0){
                  dp[i][j] = 0;
              }
          }
      }

      for (int i = 0; i < len; ++i)
          for (int j = 0; j < len; ++j)
              dp[!(i % 2)][j + 1] = str[i] == rev[j] ? dp[i % 2][j] + 1 : max(dp[i % 2][j + 1], dp[!(i % 2)][j]);

      return len - dp[len%2][len];
  }
};
//TC : O(N*N)
//SC : O(N)
