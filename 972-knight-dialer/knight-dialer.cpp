class Solution {
public:

    int m = 1e9+7;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int knightDialerUtil(int ind, int cell,vector<vector<int>> &dp){
        if(ind==0) return 1;
        
        if(dp[ind][cell]!=-1) return dp[ind][cell];
        int result = 0;
        
        for(int &nextCell : adj[cell]) {
            result = (result + knightDialerUtil(ind-1, nextCell,dp)) % m; 
        }
        
        return dp[ind][cell]=result;
    }
    int knightDialer(int n) {
        int result = 0;
        
        vector<vector<int>> dp(n+1,vector<int> (10,-1));
        for(int cell = 0; cell <= 9; cell++) {
            result = (result + knightDialerUtil(n-1, cell,dp)) % m;
        }
        
        return result;
    }
};