class Solution {
private:
    int check(int i, vector<int>& dp) {
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = (i % 2) + check(i / 2, dp);
        return dp[i];
    }
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        //vector<int> ans(n + 1);
        dp[0]=0;
        for(int i = 1; i <= n; i++) {

            dp[i]=(i%2)+dp[i/2];
        }
        return dp;
    }
};
