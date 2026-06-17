class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int,int>sumcount;
        int total_tuples=0;

        for(int a: nums1){
            for(int b:nums2){
                sumcount[a+b]++;
            }
        }

        for(int c:nums3){
            for(int d:nums4){
                int target=-(c+d);

                if(sumcount.find(target)!=sumcount.end()){
                    total_tuples+=sumcount[target];
                }
            }
        }
        return total_tuples;
    }
};