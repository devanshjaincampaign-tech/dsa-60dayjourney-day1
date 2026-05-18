//This is the Optimized approach for the Leetcode Problem:724
/*Prefix sum is used and we have tried to decrease the time complexity 
to O(n)*/

#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>&nums){
    int sum=0;
    vector<int> pivot(nums.size());
    for(int x: nums){
        sum=sum+x;
    }
    int leftsum=0;
    for(int i=0;i<nums.size();i++){
        int rightsum=sum-leftsum-nums[i];
        if(leftsum==rightsum){
            return i;
        }
        leftsum+=nums[i];
    }
    return -1;
}

int main(){

    vector<int> nums = {1,7,3,6,5,6};

    cout << pivotIndex(nums);
}
