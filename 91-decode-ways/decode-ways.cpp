class Solution {
public:
    int numRecursive(string s, int ind,vector<int> &dp){
        if(ind==s.length()) return 1;

        if(dp[ind]!=-1) return dp[ind];

        if(s[ind]=='0') return 0;

        int ways=numRecursive(s,ind+1,dp);

        if(ind+1<s.length() && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6'))){
            ways+=numRecursive(s,ind+2,dp);
        }

        return dp[ind]=ways;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        return numRecursive(s,0,dp);
    }
};