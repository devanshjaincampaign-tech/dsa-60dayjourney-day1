class Solution {
private:
    bool isprime(int n) {
        if (n == 0 || n == 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        
        while (left <= right) {
            if (isprime(left)) {
                primes.push_back(left);
            }
            left++; 
        }
        
        if (primes.size() < 2) return {-1, -1};
        
        int min_diff = INT_MAX;
        vector<int> ans = {-1, -1};
        
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                ans = {primes[i - 1], primes[i]};
            }
        }
        
        return ans;
    }
};