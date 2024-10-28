class Solution {
public:
    // Precompute prime factors for numbers up to 1000
    vector<set<int>> precomputePrimeFactors(int maxNum) {
        vector<set<int>> primeFactors(maxNum + 1);
        
        for (int i = 2; i <= maxNum; i++) {
            if (primeFactors[i].empty()) { // `i` is a prime number
                for (int j = i; j <= maxNum; j += i) {
                    primeFactors[j].insert(i);
                }
            }
        }
        return primeFactors;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        const int MAX_NUM = 1000;
        vector<set<int>> primeFactorsUpTo1000 = precomputePrimeFactors(MAX_NUM);
        set<int> distinctPrimes;

        for (int num : nums) {
            distinctPrimes.insert(primeFactorsUpTo1000[num].begin(), primeFactorsUpTo1000[num].end());
        }

        return distinctPrimes.size();
    }
};
