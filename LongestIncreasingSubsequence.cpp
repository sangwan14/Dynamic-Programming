//Memoization
class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int ind,int prev_ind,vector<int>& nums){
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
               
        int take = prev_ind==-1 or nums[ind] > nums[prev_ind] ? 1 + solve(curr+1,curr,nums) : 0;
        int notTake = solve(curr+1,prev,nums);
        
        return dp[ind][prev_ind+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int> (n,-1));
        return solve(0,-1,nums);
    }
};
//TC - O(N^2)
//SC - O(N^2) + O(N)

//Tabulation
class Solution2 {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
                int len = 0 + dp[ind+1][prev_ind+1];
                if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
                  len = max(len, 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1] = len;
            }
        }
        
        return dp[0][-1+1];
    }
};
//TC - O(N^2)
//SC - O(N^2)

//Space Optimization                            
class Solution {
    public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> curr(n+1,0), next(n+1,0);

        for(int ind=n-1; ind>=0; ind--){
            for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
                int len = 0 + next[prev_ind+1];
                if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
                    len = max(len, 1 + next[ind+1]);
                }
                curr[prev_ind+1] = len;
            }
            next = curr;
        }

        return curr[0];
    }
};
//TC - O(N^2)
//SC - O(N)                            
                            
//Binary Search
class Solution4 {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> lis;
        lis.push_back(arr[0]);
        
        for(int i=1; i<n; i++){
            auto lower = lower_bound(lis.begin(),lis.end(),arr[i]);
            if(lower==lis.end()) lis.push_back(arr[i]);
            else *lower = arr[i]; 
        }
        
        return lis.size();
    }
};
//TC - O(N*logN)
//SC - O(1)
