class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({nums[i], i});
        }
        sort(indexedNums.begin(), indexedNums.end());
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end) {
            int currentSum = indexedNums[start].first + indexedNums[end].first;
            
            if (currentSum == target) {
                return {indexedNums[start].second, indexedNums[end].second};
            }
            else if (currentSum > target) {
                end--;
            }
            else {
                start++;
            }
        }
        return {-1, -1};
    }
};