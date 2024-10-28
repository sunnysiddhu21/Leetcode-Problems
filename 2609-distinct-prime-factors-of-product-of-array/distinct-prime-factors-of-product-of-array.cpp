class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> factors;

        // Step 1: Divide by 2 until n is odd
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }

        // Step 2: Try odd factors from 3 upwards
        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }

        // Step 3: If n is still greater than 2, it must be a prime factor
        if (n > 2) {
            factors.push_back(n);
        }

        return factors;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;

        for (int num : nums) {
            vector<int> factors = primeFactors(num);
            for (int factor : factors) {
                st.insert(factor);  // Insert each factor individually
            }
        }

        return st.size(); // The size of the set gives the number of unique prime factors
    }
};