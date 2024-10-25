class Solution {
public:

    int binarySearch(vector<int>& arr, int target,int i) {
        int left = i+1;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  
            if (arr[mid] == target) {
                return mid;  
            } 
            else if (arr[mid] < target) {
                left = mid + 1;  
            } 
            else {
                right = mid - 1; 
            }
        }

        return -1;  
    }

    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        
        while(l<r){
            int total=arr[l]+arr[r];
            if(total==target){
                return {l+1,r+1};
            }else if(total>target){
                r--;
            }else{
                l++;
            }
        }
        return {-1,-1};
    }
};