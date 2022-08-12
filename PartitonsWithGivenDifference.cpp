//Can be boiled down to "count number of subsets with sum k" problem.

//Space Optimized
class Solution{
  int findWays(vector<int> &num, int k)
  {
      int n = num.size();
      const int mod = 1e9 + 7;
      vector<int> prev(k+1,0);

      prev[0] = 1;

      for(int ind = 0; ind<n; ind++){
          vector<int> cur(k+1,0);
          for(int target = 0; target<=k; target++){

              int notTaken = prev[target];

              int taken = 0;
              if(num[ind]<=target)
                  taken = prev[target-num[ind]];

              cur[target] = (notTaken + taken)%(mod);
          }

          prev = cur;
      }

      return prev[k];
  }
  int countPartitions(int n, int d, vector<int> &arr) {
      int totSum = 0;
      for(int i=0; i<n; i++) totSum+=arr[i];

      int k = (totSum-d)/2;

      return d<=totSum and (totSum-d)%2==0 ? findWays(arr,k) : 0;    
  }
};
//TC : O(N*K)
//SC : O(K)
