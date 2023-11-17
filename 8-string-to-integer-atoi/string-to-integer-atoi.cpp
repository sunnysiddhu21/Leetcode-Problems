class Solution {
public:
    int myAtoi(string s) {
        long value=1;
        long counter=1;
        bool sign=false,starts=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='-') {sign=true;
            if(i+1==s.length()||s[i+1]<48||s[i+1]>57)break;
            continue;}
            if(s[i]=='+') {sign=false;
            if(i+1==s.length()||s[i+1]<48||s[i+1]>57)break;
            continue;}
            if(s[i]==' ')continue;
            if(s[i]<48||s[i]>57)break;
            else{
                if(s[i]-48!=0||starts){value*=10;
                counter*=10;
               starts=true;}
                value+=(s[i]-48);
                     if(value-counter>2147483647){
            if(sign)return INT_MIN;
            return pow(2,31)-1;
        }
            
                if(i+1==s.length()||s[i+1]<48||s[i+1]>57)break;
            }
        }

        value-=counter;
            if(value>2147483647){
            if(sign)return INT_MIN;
            return pow(2,31)-1;
        }
        if(sign)value*=-1;
        return value;
    }
};