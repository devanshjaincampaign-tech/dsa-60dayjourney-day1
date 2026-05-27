#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> vec(52, 0);
        int count = 0;
        
        
        for (char x : word) {
            if (islower(x)) {
                vec[x - 'a']++;
            } else if (isupper(x)) {
                vec[x - 'A' + 26]++; 
            }
        }
        
        
        for (int i = 0; i < 26; i++) {
           
            if (vec[i] > 0 && vec[i + 26] > 0) {
                count++;
            }
        }
        
        return count;
    }
};