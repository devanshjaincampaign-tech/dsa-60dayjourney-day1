class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ans;
        for(int i:nums){
            if(i!=0){
                ans.push_back(i);
            }
        }
        for(int i=ans.size();i<nums.size();i++){
            ans.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=ans[i];
        }
    }
};