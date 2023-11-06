#include<bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,e=height.size()-1;
        int maxi=0;
        while(l<e){
            int min_h=min(height[l],height[e]);
            int curr_area=min_h*(e-l);

            maxi=max(maxi,curr_area);

            if(height[l]<height[e]) l++;
            else e--;
        }

        return maxi;
    }
};