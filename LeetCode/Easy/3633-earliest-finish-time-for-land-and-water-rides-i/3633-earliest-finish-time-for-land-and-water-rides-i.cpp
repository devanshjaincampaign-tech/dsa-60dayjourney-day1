

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minLandFinish = INT_MAX;
        int minWaterFinish = INT_MAX;
        
        for(int i = 0; i < landStartTime.size(); i++){
            int currentLandFinish = landStartTime[i] + landDuration[i];
            minLandFinish = min(minLandFinish, currentLandFinish);
        }
        
        for(int i = 0; i < waterStartTime.size(); i++){
            int currentWaterFinish = waterStartTime[i] + waterDuration[i];
            minWaterFinish = min(minWaterFinish, currentWaterFinish);
        }

        int landFirstTotal = INT_MAX;
        for(int i = 0; i < waterStartTime.size(); i++) {
            int actualWaterStart = max(minLandFinish, waterStartTime[i]);
            landFirstTotal = min(landFirstTotal, actualWaterStart + waterDuration[i]);
        }

        int waterFirstTotal = INT_MAX;
        for(int i = 0; i < landStartTime.size(); i++) {
            int actualLandStart = max(minWaterFinish, landStartTime[i]);
            waterFirstTotal = min(waterFirstTotal, actualLandStart + landDuration[i]);
        }

        return min(landFirstTotal, waterFirstTotal);
    }
};