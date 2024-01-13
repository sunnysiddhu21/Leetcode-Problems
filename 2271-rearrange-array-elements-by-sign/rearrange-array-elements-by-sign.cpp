class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
        int n=nums.size();
        vector<int> ans(n,0);
        
        int posIndex=0;
        int negIndex=1;

        for(int i=0; i<n; i++){
            if(nums[i]<0){
                ans[negIndex]=nums[i];
                negIndex+=2;
            }
            else{
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
        }
        
        
        return ans;
    }
};