class Solution {
public:
    int solve(int n,vector<int>&dp){
        
        dp[0]=1;
        dp[1]=1;
        
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
              dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        return solve(n,dp);
    }
};