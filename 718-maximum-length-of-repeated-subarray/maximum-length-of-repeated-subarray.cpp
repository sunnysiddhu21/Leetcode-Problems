class Solution {
public:
    int findLength(vector<int>& s, vector<int>& t) {
        int n=s.size();
        int m=t.size();
        vector<int> prev(n+1,0),curr(m+1,0);
        int ans=0;
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else curr[j]=0;
            }
            prev=curr;
        }
        return ans;
    }
};