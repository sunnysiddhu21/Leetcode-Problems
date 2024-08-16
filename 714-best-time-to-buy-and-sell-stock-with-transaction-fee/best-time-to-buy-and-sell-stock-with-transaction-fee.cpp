class Solution {
public:
    int maxProfitUtil(int ind,int n,vector<int>&prices,int fee,int buy,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;

        if(buy==0){
            profit=max(maxProfitUtil(ind+1,n,prices,fee,0,dp),-prices[ind]+maxProfitUtil(ind+1,n,prices,fee,1,dp));
        }

        if(buy==1){
            profit=max(maxProfitUtil(ind+1,n,prices,fee,1,dp),prices[ind]-fee+maxProfitUtil(ind+1,n,prices,fee,0,dp));
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int profit;

                if (buy == 0) { // We can buy the stock
                    profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + dp[ind + 1][1], prices[ind] - fee + dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }
        //return maxProfitUtil(0,n,prices,fee,0,dp);
        return dp[0][0];
    }
};