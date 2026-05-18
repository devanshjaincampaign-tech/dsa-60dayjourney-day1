//This is the Brute Force approach for the Leetcode problem: 724 (Finding the Pivotal Index)
//The main approach is using the nested loop, and prefix sum
//I have tried to find the sum of the elements from the starting index too the main index 
//And the nested loop for finding after the main index.
//Time complexity: O(n)
#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums){
    vector<int>prefix(nums.size());
    long long unsigned int sum=0;
    prefix[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]+nums[i];
        for(int j=i+1;j<nums.size();j++){
            sum=sum+nums[j];
        }
        if(prefix[i-1]==sum){
            return i;
        }
        sum=0;
    }
    return -1;
}

int main(){
    vector<int> nums={2,1,-1};
    int ans=pivotIndex(nums);

    cout<<"the pivot index is:"<<ans;
}