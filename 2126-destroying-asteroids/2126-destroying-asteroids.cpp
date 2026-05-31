class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        bool destroyed=true;
        sort(asteroids.begin(),asteroids.end());

        long long currentmass=mass;

        for(int i=0;i<asteroids.size();i++){
            if(currentmass>=asteroids[i]){
                currentmass=currentmass+asteroids[i];

            }
            else{
                destroyed=false;
            }
        }
        return destroyed;
    }
};