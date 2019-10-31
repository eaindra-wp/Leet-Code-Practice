// using stack to save the LHS parentheses and pop out when 
// the RHS parentheses have been found
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        
        if(s.length() <= 1){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(c == ']'){
                if(mystack.top() != '[' || mystack.size() == 0)
                    return false;
               else mystack.pop();
            }
            if(c == ')'){
                if(mystack.top() != '(' || mystack.size() == 0)
                    return false;
                else mystack.pop();
            }
            if(c == '}'){
                if(mystack.top() != '{' || mystack.size() == 0)
                    return false;
                else mystack.pop();
            }
            else
                mystack.push(c);
        }
        return mystack.size() == 0;
    }

};