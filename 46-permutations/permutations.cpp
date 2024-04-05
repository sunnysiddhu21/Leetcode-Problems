class Solution {
public:
    void solver(int pos,vector<vector<int>> &ans,vector<int>& nums){
        if(pos>=nums.size()) ans.push_back(nums);

        for(int i=pos; i<nums.size(); i++){
            swap(nums[i],nums[pos]);
            solver(pos+1,ans,nums);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solver(0,ans,nums);
        return ans;
    }
};