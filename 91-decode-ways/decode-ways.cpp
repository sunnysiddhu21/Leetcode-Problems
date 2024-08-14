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
        if(n==0 || s[0]=='0'){
            return 0;
        }
        vector<int> dp(n+1,0);

        dp[0]=1;
        dp[1]=1;

        for(int i=2; i<=n; i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }

            int twoDigit=stoi(s.substr(i-2,2));
            if(twoDigit>=10 && twoDigit<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};