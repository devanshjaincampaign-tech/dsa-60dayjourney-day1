class Solution {
public:
    int climbStairs(int n) {
        int term1=1,term2=1,nextterm=0;
        for(int i=1;i<n;i++){
            nextterm=term1+term2;
            term1=term2;
            term2=nextterm;
        }
        return term2;

    }
};