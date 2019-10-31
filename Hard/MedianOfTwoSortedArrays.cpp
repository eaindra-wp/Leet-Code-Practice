#include<vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n){ // check m >= n
            nums1.swap(nums2);
            int tmp;
            tmp = m; m = n; n = tmp;
            // swap
        }
        int min = 0, max = m;
        while(min <= max){
            int i = (min+max)/2;
            int j = ((m+n+1)/2) - i;
            if(i < max && nums2[j-1] > nums1[i]){
                min = i+1; 
                // i is too small 
                // nums2[j-1] <= nums1[i] must be true.
            }
            else if(nums1[i-1] > nums2[j]){
                min = i-1;
                // i is too large
                 // nums2[j] >= nums1[i-1] must be true.
            }
            else{
                int maxLeft = 0;
                if(i==0) {maxLeft = nums2[j-1];}
                else if(j==0) {maxLeft = nums1[i-1];}
                else {maxLeft = std::max(nums1[i-1], nums2[j-1]);}
                if((m+n)%2 == 1){return maxLeft;}
                // if the total size is odd, maxLeft will definitely minimum.
                
                int minRight = 0;
                if(i==m) {minRight = nums2[j];}
                else if(j==n){minRight = nums1[i];}
                else{ minRight = std::min(nums1[i], nums2[j]);}
                
                return (maxLeft + minRight)/2.0;
            }
        }
     return 0.0;   
    }
};