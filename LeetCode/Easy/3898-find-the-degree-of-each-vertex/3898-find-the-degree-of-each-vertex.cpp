class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>finalans(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(matrix[i][j]==matrix[j][i] && matrix[i][j]==1){
                    finalans[i]++;
                }
            }
        }
        return finalans;
    }
};