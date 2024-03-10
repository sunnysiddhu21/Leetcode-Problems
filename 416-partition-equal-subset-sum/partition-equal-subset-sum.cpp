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
            vector<bool> prev(k + 1, false);
            prev[0]=true;
            
            
            if (nums[0] <= k)
                prev[nums[0]] = true;

            for(int i=1; i<n; i++){
                vector<bool> cur(k + 1, false);
                cur[0] = true;
                for(int target=1; target<=k; target++){
                    bool ntake=prev[target];
                    bool take=false;
                    if(nums[i]<=target){
                        take=prev[target-nums[i]];
                    }

                    cur[target]=(ntake || take);
                }
                prev=cur;
            }
            return prev[k];
        }
    }
};