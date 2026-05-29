class Solution {
public:
    int minElement(vector<int>& nums) {
        int minval=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            while(nums[i]!=0){
                sum=sum+(nums[i]%10);
                nums[i]=nums[i]/10;

            }
            minval=min(minval,sum);

        }
        return minval;
    }
};