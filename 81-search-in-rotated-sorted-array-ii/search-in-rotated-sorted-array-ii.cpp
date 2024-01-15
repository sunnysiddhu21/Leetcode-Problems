class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int h=n-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==k) return true;
            if(arr[l]==arr[mid] && arr[mid]==arr[h]){
                l++;
                h--;
                continue;
            }

            if(arr[l]<=arr[mid]){
                if(arr[l]<=k && k<=arr[mid]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(arr[mid]<=k && k<=arr[h]){
                    l=mid+1;

                }
                else{
                    h=mid-1;
                }
            }

            
        }

        return false;
    }
};