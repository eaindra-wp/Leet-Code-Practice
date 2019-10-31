// find indexes of 2 ints which make the sum of target int
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for(int i=0; i < nums.size(); i++){
            auto result = map.find(nums[i]);
            if(result != map.end()){
                return {result->second , i};
            }
            map.emplace(target-nums[i], i);
        }
        return {-1,-1};   
    }
};