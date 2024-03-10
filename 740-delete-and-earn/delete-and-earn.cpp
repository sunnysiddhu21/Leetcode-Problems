class Solution {
    int rec(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int not_take = rec(nums, i + 1, dp);
        int take = nums[i] * i + rec(nums, i + 2, dp);

        return dp[i] = max(take, not_take);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_num = 0;
        for (int num : nums) {
            max_num = max(max_num, num);
        }

        vector<int> arr(max_num + 1, 0);
        vector<int> dp(max_num + 1, -1);

        for (int num : nums) {
            arr[num]++;
        }

        return rec(arr, 1, dp);
    }

};