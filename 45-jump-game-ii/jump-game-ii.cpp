class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        int numJumps=0;
        int currIndexReach=0;
        int maxPrevReach=0;

        for(int i=0; i<n-1; i++){
            currIndexReach=max(currIndexReach,i+nums[i]);

            if(maxPrevReach==i){
                numJumps++;
                maxPrevReach=currIndexReach;
            }
        }

        return numJumps;
    }
};