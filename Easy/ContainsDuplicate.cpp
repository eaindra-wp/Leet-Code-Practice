// sorting first and compare
#include <vector>
#include <bits/stdc++.h> 
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};