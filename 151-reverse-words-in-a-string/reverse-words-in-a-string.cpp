class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int i =0 ;
        int n = s.length();

        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            
            string word = "";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }

            if(!word.empty()){
                st.push(word);
            }
        }

        string ans;

        while(!st.empty()){
            ans+=(st.top());
            st.pop();

            if(!st.empty()){
                ans+=(' ');
            }
        }

        return ans;
    }
};