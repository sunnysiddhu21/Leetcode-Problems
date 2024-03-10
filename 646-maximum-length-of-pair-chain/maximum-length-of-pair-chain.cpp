class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,1);
        int maxL=1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                    maxL=max(maxL,dp[i]);
                }
            }
        }

        return maxL;
    }
};