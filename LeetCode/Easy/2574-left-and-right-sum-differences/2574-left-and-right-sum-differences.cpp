class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalsum=0;
        int leftsum=0;
        vector<int>finalans;

        for(int num:nums){
            totalsum+=num;
        }


        for(int num:nums){
            int rightsum=totalsum-num-leftsum;
            finalans.push_back(abs(rightsum-leftsum));
            leftsum+=num;
        }
        return finalans;
    }
};