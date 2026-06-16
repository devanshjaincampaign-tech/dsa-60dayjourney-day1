class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> finalans;
        if(firstList.empty() || secondList.empty()) return finalans;

        int n = firstList.size();
        int m = secondList.size();

        
        int i = 0; 
        int j = 0;

        while(i < n && j < m) {
           
            int startMax = max(firstList[i][0], secondList[j][0]);
            int endMin = min(firstList[i][1], secondList[j][1]);

            
            if (startMax <= endMin) {
                vector<int> mergedintervals;
                mergedintervals.push_back(startMax);
                mergedintervals.push_back(endMin);
                finalans.push_back(mergedintervals);
            }

            
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return finalans;
    }
};