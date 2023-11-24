class Solution {
public:
    int f(int i,int j,string &s, string &t ){
        if(i<0) return j+1;  //base case
        if(j<0) return i+1;  //base case
        if(i=0) return j;  //base case
        if(j=0) return i;

        if(s[i]==t[j]) return f(i-1,j-1,s,t);

        return 1+min(f(i-1,j,s,t),min(f(i,j-1,s,t),f(i-1,j-1,s,t)));
    }

    int minDistance(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        for(int j =0; j<= m; j++){
            prev[j] = j;
        }

        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min(curr[j-1],min(prev[j-1],prev[j]));
            }
            prev=curr;
        }

        return prev[m];
    }
};