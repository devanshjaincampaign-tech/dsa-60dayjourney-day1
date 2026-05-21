#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool ispalindrome(string s){

    string ch="";
    for(char x: s){
        if(isalnum(x)){ //isalnum is used to check whether a character is a letter or a number, hence we can use it to filter out the characters
            ch.push_back(tolower(x));//converts every characcter to the lower case to check with uniformity in case sensitivity 
        }
    }
    string ch1=ch;
    reverse(ch.begin(),ch.end());

    if(ch1==ch){
        return true;
    }
    return false;
}
