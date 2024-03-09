class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Sort the input array to make the divisibility condition easier to check.
        sort(nums.begin(), nums.end());
      
        // Get the size of the array.
        int n = nums.size();
        // Array to store the size of the largest divisible subset that ends with nums[i].
        vector<int> subsetSizes(n, 1);
      
        // Variable to keep track of the index at which the largest subset ends.
        int maxSubsetIndex = 0;
      
        // Calculate the size of the largest subset where each element is divisible by its previous ones.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    // If nums[i] is divisible by nums[j], consider this as a potential maximum size.
                    subsetSizes[i] = max(subsetSizes[i], subsetSizes[j] + 1);
                }
            }
            // Update the index of the largest subset if the current one is larger.
            if (subsetSizes[maxSubsetIndex] < subsetSizes[i]) {
                maxSubsetIndex = i;
            }
        }

        // Construct the largest subset by iterating from the end to the beginning of the subset.
        int currentSize = subsetSizes[maxSubsetIndex];
        vector<int> largestSubset;
        for (int i = maxSubsetIndex; currentSize > 0; --i) {
            // If nums[i] is part of the subset, add it to the result.
            if (nums[maxSubsetIndex] % nums[i] == 0 && subsetSizes[i] == currentSize) {
                largestSubset.push_back(nums[i]);
                // Update the index to the last added number and decrement the currentSize.
                maxSubsetIndex = i;
                --currentSize;
            }
        }
        // Return the constructed largest divisible subset.
        return largestSubset;
    }
};