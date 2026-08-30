class Solution {
public:
    long long binaryExp(long long base, long long exp) {
        long long MOD = 1e9 + 7;
        long long res = 1;
        base %= MOD;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        long long MOD = 1e9 + 7;
        long long total_sum = 0;

        for (long long num : nums) {
            int w = num % 10;
            long long d = num / 10;

            long long temp = d;
            int total_digits = 0;
            while (temp > 0) {
                total_digits++;
                temp /= 10;
            }

            long long divisor = 1;
            for (int i = 0; i < total_digits - w; ++i) {
                divisor *= 10;
            }

            long long x = d / divisor;
            long long y = d % divisor;

            total_sum = (total_sum + binaryExp(x, y)) % MOD;
        }

        return total_sum;
    }
};