class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> sorted_array;
        
        while(!nums1.empty() && !nums2.empty()){
            if(nums1.front() <= nums2.front()){
                sorted_array.push_back(nums1.front());
                nums1.erase(nums1.begin());
            }
            else {
                sorted_array.push_back(nums2.front());
                nums2.erase(nums2.begin());
            }
        }

        while(!nums1.empty()){
            sorted_array.push_back(nums1.front());
            nums1.erase(nums1.begin());
        }
        while(!nums2.empty()){
            sorted_array.push_back(nums2.front());
            nums2.erase(nums2.begin());
        }

        if(n % 2 == 0){
            return (sorted_array[(n/2) - 1] + sorted_array[n/2]) / 2.0;
        }
        return sorted_array[n/2];
    }
};