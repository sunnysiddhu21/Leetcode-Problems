class Solution {
public:
    
    int integerBreakUtil(int n,vector<int>&dp){
        if(n==0) return 0;
        int result=INT_MIN;
        if(dp[n]!=-1) return dp[n];

        for(int i=1; i<=n-1; i++){
            int prod=i*max(n-i,integerBreakUtil(n-i,dp));
            //  max(j * (i - j), j * dp[i - j])
            result=max(result,prod);
        }

        return dp[n]=result;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;  // Base case: The maximum product for 1 is itself

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // Considering both j and i-j to ensure the product maximizes
                dp[i] = max(dp[i], j*max((i - j),dp[i - j]));
            }
        }

        return dp[n];
    }
};