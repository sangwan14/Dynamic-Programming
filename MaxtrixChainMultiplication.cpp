class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N-1, vector<int> (N-1,0));
        
        for(int g=1; g<dp.size(); g++){
            for(int i=0, j=g; j<dp.size(); i++,j++){
                if(g==1){
                    dp[i][j] = arr[i]*arr[i+1]*arr[i+2];
                }
                else {
                    int mini = INT_MAX;
                    for(int k=i; k<j; k++){
                        int l = dp[i][k];
                        int r = dp[k+1][j];
                        int m = arr[i]*arr[k+1]*arr[j+1];
                        if(l+r+m < mini)
                            mini = l+r+m;
                    }
                    dp[i][j] = mini;
                }
            }
        }
        
        return dp[0][dp.size()-1];
    }
};
//TC - O(N^3)
//SC - O(N^2)
