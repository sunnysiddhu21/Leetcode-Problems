class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(nums[i]<mini){
                mini=nums[i];
            }
        }

        int ans=sum-mini*n;

        return ans;
    }
};