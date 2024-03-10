class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        int maxL=1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1==dp[i]){
                        hash[i]+=hash[j];
                    }
                    else if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        hash[i]=hash[j];
                    }
                }
            }
        }
        int maxi=*max_element(begin(dp),end(dp));
        int cnt=0;
        for(int i=0; i<n; i++){
            if(maxi==dp[i]){
                cnt+=hash[i];
            }
        }
        
        return cnt;
    }
};