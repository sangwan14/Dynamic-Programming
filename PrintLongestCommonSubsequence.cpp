#include<bits/stdc++.h>

using namespace std;

string longestCommonSubsequence(string &a, string &b){
	int n = a.size();
	int m = b.size();

	vector<vector<int>> dp(n+1, vector<int> (m+1,0));

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dp[i+1][j+1] = a[i]==b[j] ? dp[i][j] + 1 : max(dp[i+1][j],dp[i][j+1]);
		}
	}

	string res = "";
	int len = max(n,m);
	for(int i=0; i<len; i++){
		res+='*';
	}
	
	int index = len-1;
	int i,j;
	i=n; j=m;

	while(i>0 and j>0){
			if(a[i-1]==b[j-1]){
				res[index] = a[i-1];
				index--;
				i--; j--;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]) i--;
				else j--;
			}
	}

	return res;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string a,b;
	cin>>a>>b;
	

	cout<<longestCommonSubsequence(a,b)<<endl;

	return 0;
}
