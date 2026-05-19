#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longesSubstring(string s){
    int n = s.length();
    
    // Edge case: if the string is empty, the longest substring is 0
    if (n == 0) return 0;
    
    int maxcount = 1;

    // Outer loop: pick the starting point 'i'
    for (int i = 0; i < n; i++) {
        
        // Fix 1: Create a fresh checklist for characters seen in THIS substring
        // ASCII size 256 covers all standard characters initialized to false
        vector<bool> seen(256, false); 
        
        // Mark the starting character as seen
        seen[s[i]] = true;
        int currcount = 1; // Fix 2: Reset currcount for this new starting point
        
        // Inner loop: extend the substring with 'j'
        for (int j = i + 1; j < n; j++) {
            
            // Fix 3: Check if s[j] has been seen ANYWHERE in the current substring
            if (seen[s[j]]) {
                break; // Found a duplicate! Stop extending this substring.
            }
            
            seen[s[j]] = true; // Mark this character as seen
            currcount++;       // Increment the current valid substring length
        }
        
        maxcount = max(maxcount, currcount);
    }
    return maxcount;
}

int main(){
    string s="abcabcbb";
    int longest=longesSubstring(s);

    cout<<"The longest substring is:"<<longest;
}