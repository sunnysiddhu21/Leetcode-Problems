class Solution {
public:
    
    int integerBreakUtil(int n,vector<int>&dp){
        if(n==0) return 0;
        int result=INT_MIN;
        if(dp[n]!=-1) return dp[n];

        for(int i=1; i<=n-1; i++){
            int prod=i*max(n-i,integerBreakUtil(n-i,dp));
            result=max(result,prod);
        }

        return dp[n]=result;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return integerBreakUtil(n,dp);
    }
};