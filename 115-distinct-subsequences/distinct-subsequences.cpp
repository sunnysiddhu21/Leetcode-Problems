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

    int numDistinct(string str, string sub) {
        int n=str.size();
	int m=sub.size();
	vector<int> prev(m+1,0);
	prev[0]=1;

	for(int i=1; i<=n; i++){
		for(int j=m; j>=1; j--){
			if(str[i-1]==sub[j-1]) prev[j]=(prev[j-1]+prev[j])%mod;
			
		}
		
	}
    return prev[m]%mod;
    }
};