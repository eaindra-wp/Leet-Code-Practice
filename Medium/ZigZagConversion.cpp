#include <string>
using std::string;
#include <vector>
class Solution {
public:
    string convert(std::string s, int numRows) {
        if(numRows == 1) return s;
        // no zigzag will be made
        
        std::vector<string> rows(std::min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown; //change goingDown status
            }
            currentRow += goingDown ? 1 : -1; // if goingDown is still true, we will go to the new row. 
        }

        string result;
        for (string row : rows) result += row;
        return result;
    }
};