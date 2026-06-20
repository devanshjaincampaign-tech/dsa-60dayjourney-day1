class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // 1. Add the baseline boundaries
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        // Sort restrictions by building index
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // 2. Left-to-Right Pass: Limit heights based on previous restrictions
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + dist);
        }
        
        // 3. Right-to-Left Pass: Limit heights based on subsequent restrictions
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + dist);
        }
        
        // 4. Calculate the absolute max height possible between any two restrictions
        int max_height = 0;
        for (int i = 0; i < m - 1; i++) {
            int h1 = restrictions[i][1];
            int h2 = restrictions[i+1][1];
            int idx1 = restrictions[i][0];
            int idx2 = restrictions[i+1][0];
            
            // Peak formula between two bounded points
            int peak = (h1 + h2 + (idx2 - idx1)) / 2;
            max_height = max(max_height, peak);
        }
        
        return max_height;
    }
};