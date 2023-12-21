class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        long result = 0;

        // Skip leading whitespaces
        while (i < str.length() && str[i] == ' ') {
            i++;
        }

        // Check for optional sign character
        if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i++] == '-') ? -1 : 1;
        }

        // Process digits
        while (i < str.length() && isdigit(str[i])) {
            result = result * 10 + (str[i++] - '0');

            // Check for integer overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return result * sign;
    }
};