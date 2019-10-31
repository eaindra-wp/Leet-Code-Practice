#include <string>
using std::string;
class Solution {
public:
    string longestPalindrome(string s) {
      
        if(s == "" || s.length()<1) {
            return ""; // return emptystring
        }
        int start = 0, end = 0;
        for(int i=0; i<s.length(); i++){
            int len1 = mirrorCheck(s,i,i);
            int len2 = mirrorCheck(s,i,i+1);
            // for the case like bb in the substring
            
            int len = std::max(len1,len2);
            
            if(len > end-start){
                start = i-((len-1)/2);
                end = i + (len/2);
            }
        }
        return s.substr(start, end);
    }
    // check same chars around the center char
    int mirrorCheck(string s,int left, int right){
        int l = left, r = right;
        while(l>=0 && r<s.length() && s.at(l) == s.at(r)){
            l--;
            r++;
        }
        return r-l-1;
    }
};