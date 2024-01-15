class Solution {
public:
    int lowerBound(vector<int>& nums, int n,int k){
        int l=0;
        int h=n-1;
        int ans=n;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>=k){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int n,int k){
        int l=0;
        int h=n-1;
        int ans=n;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>k){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerBound(nums,n,target);
        vector<int> res;
        if(lb==n || nums[lb]!=target){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int ub=upperBound(nums,n,target);
        res.push_back(lb);
        res.push_back((ub-1));
        return res;
    }
};