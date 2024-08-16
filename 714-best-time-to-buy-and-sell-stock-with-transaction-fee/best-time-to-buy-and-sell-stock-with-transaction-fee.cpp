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
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return maxProfitUtil(0,n,prices,fee,0,dp);
    }
};