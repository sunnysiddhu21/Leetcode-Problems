class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> merged;
        if(n==0) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];

        for(auto it: intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                merged.push_back(temp);
                temp=it;
            }
        }
        merged.push_back(temp);
        return merged;

    }
};