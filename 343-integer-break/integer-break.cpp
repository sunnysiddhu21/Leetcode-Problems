class Solution {
public:
    
    int integerBreakUtil(int ind,vector<int>&v,int sum,int &k,vector<vector<int>>&dp){
        int n=v.size();

        if(ind==n || sum==n){
            if(k>=2) return 1;
            return 0;
        }

        if(dp[ind][sum]!=-1) return dp[ind][sum];

        int ntake=integerBreakUtil(ind+1,v,sum,k,dp);
        int take=1;
        if(sum+v[ind]<=n){
            k++;
            take=v[ind]*integerBreakUtil(ind,v,sum+v[ind],k,dp);
        }

        return dp[ind][sum]=max(take,ntake);
    }

    int integerBreak(int n) {
        if(n==1) return 1;
        if(n==0) return 0;
        
        vector<int> v;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }

        int k=0;

        return integerBreakUtil(0,v,0,k,dp);
    }
};