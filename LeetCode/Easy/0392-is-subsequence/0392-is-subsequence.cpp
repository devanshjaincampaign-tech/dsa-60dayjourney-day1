class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> index;
        int last_found_pos = -1;
        
        for(char x : s){
            bool found = false;
            for(int i = last_found_pos + 1; i < t.size(); i++){
                if(x == t[i]){
                    index.push_back(i);
                    last_found_pos = i;
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        
        bool istrue = true;
        for(int i = 1; i < index.size(); i++){
            if(index[i] <= index[i-1]){
                istrue = false;
            }
        }
        return istrue;
    }
};