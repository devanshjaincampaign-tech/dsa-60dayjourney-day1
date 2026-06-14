class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex + 1);
        vec[0] = 1;
        
        long long current = 1;
        for (int i = 1; i <= rowIndex; i++) {
            current = current * (rowIndex - i + 1) / i;
            vec[i] = current;
        }
        
        return vec;
    }
};