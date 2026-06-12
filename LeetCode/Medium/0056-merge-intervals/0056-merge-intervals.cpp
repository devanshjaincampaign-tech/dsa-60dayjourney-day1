class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        // Track which intervals have already been merged/consumed
        vector<bool> merged(intervals.size(), false);
        
        for (int i = 0; i < intervals.size(); i++) {
            // Skip if this interval was already swallowed by a previous one
            if (merged[i]) continue; 
            
            for (int j = i + 1; j < intervals.size(); j++) {
                // Correct overlap condition: next start <= current end
                if (intervals[j][0] <= intervals[i][1]) {
                    // Update current interval's end to the absolute maximum
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    // Mark interval j as consumed
                    merged[j] = true; 
                } else {
                    // Because it's sorted, if j doesn't overlap, 
                    // no subsequent intervals will overlap with i either.
                    break; 
                }
            }
            // Push the fully expanded intervals[i]
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};