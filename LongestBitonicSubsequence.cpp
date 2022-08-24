class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
	    
	    for(int i=0; i<n; i++){
	        for(int prev=0; prev<i; prev++){
	            if(nums[i]>nums[prev] and 1+dp1[prev]>dp1[i])
	                dp1[i] = 1+dp1[prev];
	        }
	    }
	    for(int i=n-1; i>=0; i--){
	        for(int next=n-1; next>i; next--){
	            if(nums[i]>nums[next] and 1+dp2[next]>dp2[i])
	                dp2[i] = 1+dp2[next];
	        }
	    }
	    
	    int maxi = 1;
	    for(int i=0; i<n; i++){
	        maxi = max(dp1[i]+dp2[i]-1,maxi);
	    }
	    
	    return maxi;
	}
};
//TC - O(N*N)
//SC - O(N)
