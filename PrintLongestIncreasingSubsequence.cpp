#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> printLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1), predecessor(n);
        int last_index = 0;
        int maxi = 1;
        for(int ind=0; ind<n; ind++){
        	predecessor[ind] = ind;
            for(int prev=0; prev<ind; prev++){
                if(arr[ind]>arr[prev] and 1+dp[prev]>dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    predecessor[ind] = prev;
                }
            }
            if(dp[ind]>maxi){
            	maxi = dp[ind];
            	last_index = ind;
            }
        }

        vector<int> lis;
        lis.push_back(arr[last_index]);

        while(predecessor[last_index]!=last_index){
            last_index = predecessor[last_index];
            lis.push_back(arr[last_index]);
        }

        reverse(lis.begin(),lis.end());

        return lis;
    }
};

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vector<int> nums = {10, 9, 2, 5, 3, 6, 8, 12};
	int n =  nums.size();
	vector<vector<int>> dp(n+1, vector<int> (n+1,0));

	Solution obj;
	vector<int> lis = obj.printLIS(nums);
	int len = lis.size();
	for(int i=0; i<len; i++) cout<<lis[i]<<" ";

	return 0;	
}
