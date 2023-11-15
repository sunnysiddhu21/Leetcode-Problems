class Solution {
public:
    int mod =(int)1e9+7;
    int recurr(int i,int j,string &str,string &sub,vector<vector<int>> &dp){
	if(j<0) return 1;
	if(i<0) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	if(str[i] == sub[j])
	return dp[i][j] = (recurr(i-1, j-1, str, sub, dp) +
	recurr(i-1, j, str, sub, dp))%mod;
	else
	return dp[i][j] = recurr(i-1, j, str, sub, dp)%mod;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};