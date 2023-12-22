class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        if(nn < 0) nn = -1 * nn;

        while(nn > 0){
            // If Odd Power
            if(nn % 2 == 1){
                ans = ans * x;
                nn -= 1;
            } 
            // If Even Power
            else {
                x = x * x;
                nn /= 2;
            }
        }

        // We do a check for the value of N, if it was negative, we give the answer as 1/answer in decimals
        if(n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};