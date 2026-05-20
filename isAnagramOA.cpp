// Optimized Approach (Using Frequency Array)
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Approach:
// 1. First check if both strings have the same length.
//    If lengths are different, return false.
//
// 2. Create a frequency array of size 26
//    to store counts of lowercase English letters.
//
// 3. Traverse the first string:
//    - Increment frequency for each character.
//
// 4. Traverse the second string:
//    - Decrement frequency for each character.
//
// 5. Finally check the frequency array:
//    - If all values are 0 -> strings are anagrams.
//    - Otherwise -> not anagrams.
//
// Why it works:
// Both strings must contain the exact same
// characters with the exact same frequencies.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(string s, string t){
    vector<int> anagram(26,0);
    for(char x:s){
        anagram[x-'a']++;
    }
    for(char x:t){
        anagram[x-'a']--;
    }

    for (auto& p : anagram)
        {
            if (p!= 0) return false;
        }
        return true;
}

int main(){
    string s="anagram";
    string t="nagaram";

    if(isAnagram(s,t)){
        cout<<"anagram";
    }
}