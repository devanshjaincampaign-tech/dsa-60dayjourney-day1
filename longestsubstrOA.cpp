#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For max()

using namespace std;

int longestSubstringOptimized(string s) {
    int n = s.length();
    int maxcount = 0;
    
    // A checklist for characters in our current window (ASCII size 256)
    vector<bool> seen(256, false);
    
    int left = 0; // The left boundary of our window

    // The right boundary expands the window step-by-step
    for (int right = 0; right < n; right++) {
        
        // If s[right] is already in our window, shrink the window from the left
        // until s[right] is no longer a duplicate.
        while (seen[s[right]]) {
            seen[s[left]] = false; // Erase the character leaving the window
            left++;                // Move the left edge inward
        }
        
        // Add the new character to our checklist
        seen[s[right]] = true;
        
        // The size of our current valid window is (right - left + 1)
        maxcount = max(maxcount, right - left + 1);
    }
    
    return maxcount;
}

int main() {
    string s = "abcabcbb";
    int longest = longestSubstringOptimized(s);

    cout << "The longest substring is: " << longest << endl; // Output: 3
    return 0;
}