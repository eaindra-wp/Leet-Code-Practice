using namespace std;
#include<bits/stdc++.h> 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int check = 0;
        // using XOR to compare the characters
        for(int i=0; i<s.length(); i++){
            check = check ^ (int)s[i];
            check = check ^ (int)t[i];
        }
        return (check == 0);
    }
};