class Solution { 
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;  // Initialize to -1 since -1 is the return value when no difference is found
        int mini = nums[0];  // Initialize mini with the first element
        
        for(int i = 1; i < n; i++) {
            int curr = nums[i] - mini;
            maxi = max(maxi, curr);  // Update maxi with the current maximum difference
            
            mini = min(mini, nums[i]);  // Update mini to the minimum encountered so far
        }
        
        if(maxi<=0){
            return -1;
        }
        
        return maxi;
    }
};