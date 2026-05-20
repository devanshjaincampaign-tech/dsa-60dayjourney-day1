// Brute Force Approach (Using Sorting)
// Time Complexity: O(n log n)
// Space Complexity: O(1) or O(n) depending on sorting implementation
//
// Approach:
// 1. First check if both strings have the same length.
//    If lengths are different, they cannot be anagrams.
//
// 2. Sort both strings alphabetically.
//
// 3. Compare the sorted strings.
//    - If both are equal -> strings are anagrams.
//    - Otherwise -> not anagrams.
//
// Why it works:
// Anagrams contain the same characters with the same frequency.
// After sorting, both strings become identical if they are anagrams.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isAnagram(string s, string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t){
        return true;
    }
    return false;
    
}

int main(){
    string s="car";
    string t="rat";

    if(isAnagram(s,t)){
        cout<<"anagram";

    }
    else{
        cout<<"non-anagram";
    }
}