class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            // Prevents potential integer overflow compared to (start + end) / 2
            int mid = start + (end - start) / 2; 

            if (nums[mid] == target) {
                return mid; // Target found
            } 
            else if (nums[mid] < target) {
                start = mid + 1; // Search in the right half
            } 
            else {
                end = mid - 1; // Search in the left half
            }
        }

        // If the target is not found, 'start' will hold the insertion index
        return start;
    }
};