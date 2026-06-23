class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size() - 1;
        
       
        while(start <= end){ 
            int left = 0;
            
            int right = matrix[start].size() - 1; 
            
            while(left <= right){
                int mid = left + (right - left) / 2;
                
                
                if(matrix[start][mid] == target){ 
                    return true;
                }
                
                else if(matrix[start][mid] > target){
                    right = mid - 1; 
                }
                else{
                    left = mid + 1; 
                }
            }
            start++;
        }
        return false;
    }
};