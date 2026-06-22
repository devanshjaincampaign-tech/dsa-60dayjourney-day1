class Solution {
private:
    int tribonaccimemo(int n,vector<int>&memo){
        if(n==0)return 0;
        if(n==1 || n==2)return 1;

        if(memo[n]!=-1){
            return memo[n];
        }

        memo[n]=tribonaccimemo(n-1,memo)+tribonaccimemo(n-2,memo)+tribonaccimemo(n-3,memo);
        return memo[n];
    }
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1 || n==2)return 1;

        vector<int>memo(n+1,-1);
        return tribonaccimemo(n,memo);
    }
};