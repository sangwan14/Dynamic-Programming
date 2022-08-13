//Space Optimized
class Solution{
  int findWays(vector<int> &num, int k)
  {
      int n = num.size();
      vector<int> prev(k+1,0);

      prev[0] = 1;

      for(int ind = 0; ind<n; ind++){
          vector<int> cur(k+1,0);
          for(int target = 0; target<=k; target++){

              int notTaken = prev[target];

              int taken = 0;
              if(num[ind]<=target)
                  taken = prev[target-num[ind]];

              cur[target] = (notTaken + taken);
          }
          prev = cur;
      }

      return prev[k];
  }

  int targetSum(int n, int target, vector<int>& arr) {
      int totSum = 0;
      for(int i=0; i<n; i++) totSum+=arr[i];

      int k = (totSum-target)/2;

      return target<=totSum and (totSum-target)%2==0 ? findWays(arr,k) : 0;   
  }
};
//TC : O(N) + O(N*k)
//SC : O(k)
