class Solution {
public:
    int fib(int n) {
        int term1=0,term2=1,nextterm=0;
        for(int i=0;i<n;i++){
            nextterm=term1+term2;
            term1=term2;
            term2=nextterm;
        }
        return term1;
    }
};