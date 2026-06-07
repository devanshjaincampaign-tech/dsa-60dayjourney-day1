class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for(int i:nums){
            count[i]++;
        }
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        for(const auto& [nums,freq]: count){
            bucket[freq].push_back(nums);
        }

        vector<int>result;
        for(int i=n;i>=0;i--){
            for(int nums:bucket[i]){
                result.push_back(nums);
                if(result.size()==k){
                    return result;
                }
            }
        }
        return result;
    }
};