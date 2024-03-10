class Solution {
public:
    bool solver(int ind,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool ntake=solver(ind-1,target,nums,dp);
        bool take=false;
        if(nums[ind]<=target){
            take=solver(ind-1,target-nums[ind],nums,dp);
        }

        return dp[ind][target]=(ntake || take);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        for(int i=0; i<n; i++){
            tsum+=nums[i];
        }

        if(tsum%2==1){
            return false;
        }
        else{
            int k=tsum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return solver(n-1,k,nums,dp);
        }
    }
};