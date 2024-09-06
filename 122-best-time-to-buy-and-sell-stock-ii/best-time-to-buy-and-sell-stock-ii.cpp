class Solution {
public:
    int maxProfitUtils(int ind,vector<int>& prices,int buy,vector<vector<int>>& dp){
        if(ind==prices.size()) return 0;
        int profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1){
            int take=-prices[ind]+maxProfitUtils(ind+1,prices,0,dp);
            int ntake=0+maxProfitUtils(ind+1,prices,1,dp);
            profit=max(take,ntake);
        }else{
            int take=+prices[ind]+maxProfitUtils(ind,prices,1,dp);
            int ntake=0+maxProfitUtils(ind+1,prices,0,dp);
            profit=max(take,ntake);
        }

        return dp[ind][buy]=profit;
        
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return maxProfitUtils(0,prices,1,dp);
    }
};