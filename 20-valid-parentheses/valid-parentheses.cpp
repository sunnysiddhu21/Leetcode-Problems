class Solution {
public:
    bool isValid(string s) {
        int n=s.length();

        if(n==0 || n==1) return false;
        stack<int> st;

        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()==false){
                    if(s[i]==')' && st.top()=='(') st.pop();
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    else return false;
                }
                else return false;
            }
        }

        if(st.empty()) return true;
        return false;
    }
};