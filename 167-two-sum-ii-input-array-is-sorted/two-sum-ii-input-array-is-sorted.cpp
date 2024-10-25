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
        vector<int> ans;

        for(int i=0; i<n; i++){
            int mid=binarySearch(arr,target-arr[i],i);
            if(mid!=-1){
                return {i + 1, mid + 1};
            }
        }
        return {};
    }
};