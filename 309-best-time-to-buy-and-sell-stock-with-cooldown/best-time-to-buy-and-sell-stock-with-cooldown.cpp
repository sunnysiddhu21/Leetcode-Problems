class Solution {
public:
    
    int solve(int ind,int n,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(ind>=n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit=0;

        if(buy==0){
            profit=max(0+solve(ind+1,n,0,prices,dp),-prices[ind]+solve(ind+1,n,1,prices,dp));
        }

        if(buy==1){
            profit=max(0+solve(ind+1,n,1,prices,dp),prices[ind]+solve(ind+2,n,0,prices,dp));
        }

        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(0,n,0,prices,dp);
    }
};