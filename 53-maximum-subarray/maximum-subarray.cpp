class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum,maxSum;
        curSum = 0;
        maxSum = INT_MIN;

        for(int val : nums){
            curSum += val;
            maxSum = max(curSum,maxSum);
            if(curSum < 0)
                curSum = 0;
        }
        return maxSum;
    }
};