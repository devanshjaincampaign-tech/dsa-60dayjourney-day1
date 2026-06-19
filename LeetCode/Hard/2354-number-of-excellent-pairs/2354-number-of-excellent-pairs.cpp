class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        vector<int> bitCounts;
        bitCounts.reserve(nums.size());
        for (int num : nums) {
            bitCounts.push_back(__builtin_popcount(num));
        }
        
        sort(bitCounts.begin(), bitCounts.end());
        
        long long count = 0;
        int left = 0;
        int right = bitCounts.size() - 1;
        
        while (left <= right) {
            if (bitCounts[left] + bitCounts[right] >= k) {
                count += (right - left) * 2 + 1;
                right--;
            } else {
                left++;
            }
        }
        
        return count;
    }
};