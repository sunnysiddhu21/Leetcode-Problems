class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
        int n=nums.size();
        vector<int> pos;
        vector<int> neg;
        
        // Segregate the array into positives and negatives.
        for(int i=0;i<n;i++){
            
            if(nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        
        // Positives on even indices, negatives on odd.
        for(int i=0;i<n/2;i++){
            
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        
        
        return nums;
    }
};