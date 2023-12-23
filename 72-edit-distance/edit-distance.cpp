class Solution {
public:
    int f(int i,int j,string &s, string &t , vector<vector<int>> &dp ){
        if(i==0) return j;  //base case
        if(j==0) return i;  //base case
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]) return dp[i][j]=f(i-1,j-1,s,t,dp);

        return dp[i][j]=1+min(f(i-1,j,s,t,dp),min(f(i,j-1,s,t,dp),f(i-1,j-1,s,t,dp)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for (int i=0; i<=n; i++) dp[i][0] = i;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};