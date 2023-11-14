class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<int> prev(m+1,0),curr(m+1,0);

        
        
        for(int j=0; j<=m; j++)
            prev[j]=0;  // base case tabulation

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                    if (s[i-1] == t[j-1]) {
                        curr[j] = 1 +prev[j-1];
                    } 
                    else {
                        curr[j] =
                            max(prev[j],curr[j-1]);
                    }
            }
            prev=curr;
        }
            return prev[m];
    }

    int minDistance(string s1, string s2) {
        
        return (s1.size()+s2.size()-2*(longestCommonSubsequence(s1,s2)));
    }
};