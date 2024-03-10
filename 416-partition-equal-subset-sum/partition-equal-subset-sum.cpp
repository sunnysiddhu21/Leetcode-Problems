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
            vector<vector<int>> dp(n,vector<int>(k+1,false));
            
            for(int i=0; i<n; i++){
                dp[i][0]=true;
            }
            if (nums[0] <= k)
                dp[0][nums[0]] = true;

            for(int i=1; i<n; i++){
                for(int target=1; target<=k; target++){
                    bool ntake=dp[i-1][target];
                    bool take=false;
                    if(nums[i]<=target){
                        take=dp[i-1][target-nums[i]];
                    }

                    dp[i][target]=(ntake || take);
                }
            }
            return dp[n-1][k];
        }
    }
};