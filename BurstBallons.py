#Memoization
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        @cache
        def dfs(i,j):
            if i+1==j:
                return 0
            maxi = 0
            for k in range(i+1,j):
                maxi = max(maxi,nums[i]*nums[k]*nums[j] + dfs(i,k) + dfs(k,j))
            return maxi
        return dfs(0,len(nums)-1)
      
# DP (Gap Method)
class Solution2:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0 for i in range(n)] for i in range(n)]
        for gap in range(2,n):
            for i in range(n-gap):
                j = i + gap
                for k in range(i+1,j):
                    dp[i][j] = max(dp[i][j],nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j])
        return dp[0][n-1]
