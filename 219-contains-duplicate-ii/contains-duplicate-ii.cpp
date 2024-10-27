class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            // Check if the number already exists in the map
            if (mp.find(nums[i]) != mp.end() && abs(i - mp[nums[i]]) <= k) {
                return true;
            }
            // Update the map with the current index
            mp[nums[i]] = i; // Corrected from mp.insert(arr[i], i);
        }
        return false;
    }
};
