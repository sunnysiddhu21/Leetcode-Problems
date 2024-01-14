class Solution {
public:
    vector<int> genRow(int n){
        vector<int> a;
        a.push_back(1);
        long x=1;
        for(int i=0; i<n; i++){
            x*=(n-i);
            x/=(i+1);
            a.push_back(x);
        }
        return a;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            ans.push_back(genRow(i));
        }

        return ans;
    }
};
