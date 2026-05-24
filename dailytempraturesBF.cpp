/**
 * Calculates the number of days until a warmer temperature occurs for each day.
 * * Approach: Brute Force (Nested Loops)
 * Time Complexity: O(N^2) - Where N is the number of days. For each day, we scan 
 * potentially all subsequent days.
 * Space Complexity: O(1) - Auxiliary space, excluding the output vector.
 *
 * @param temperatures A vector of daily temperatures.
 * @return A vector of integers representing the wait time for a warmer day.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> dailytempratures(vector<int>& tempratures){
    vector<int>answers;
    for(int i=0;i<tempratures.size();i++){
        for(int j=i+1;j<tempratures.size();j++){
            if(tempratures[j]>tempratures[i]){
                answers.push_back(j-i);
                break;
            }
        }
    }
    return answers;
}