class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>frequency(nums.size(),0);
        for(int i:nums){
            frequency[i]++;
        }
        for(int i=0;i<frequency.size();i++){
            if(frequency[i]>=2){
                return i;
            }
        }
        return -1;
    }
};