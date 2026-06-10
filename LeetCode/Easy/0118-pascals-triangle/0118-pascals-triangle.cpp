class Solution {
private:
    // Change BOTH the return type and parameter to __int128_t
    __int128_t fact(__int128_t x){
        if(x==0) return 1;
        return x*fact(x-1);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> numrows;
        
        for(int i=0; i<numRows; i++){
            vector<int> digits;
            for(int j=0; j<=i; j++){
                
                digits.push_back(fact(i)/(fact(i-j)*fact(j)));
            }
            numrows.push_back(digits);
        }
        return numrows;
    }
};