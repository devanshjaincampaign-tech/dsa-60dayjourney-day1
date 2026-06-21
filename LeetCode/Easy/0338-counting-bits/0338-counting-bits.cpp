class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);

        for (int i = 0; i <= n; i++) {
            int a = i;
            int count = 0;

            while (a > 0) {
                if (a % 2 == 1) {
                    count++;
                }
                a = a / 2;
            }

            bits[i] = count;
        }

        return bits;
    }
};