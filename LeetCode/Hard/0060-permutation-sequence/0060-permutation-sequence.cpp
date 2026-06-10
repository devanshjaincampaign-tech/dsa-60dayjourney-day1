class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>numbers;
        for(int i=1;i<=n;i++){
            numbers.push_back(i);
        }
        
        for(int i=1;i<k;i++){
            next_permutation(numbers.begin(),numbers.end());
        }
        string num="";
        for(int i:numbers){
            num+=(i+'0');
        }
        return num;
    }
};