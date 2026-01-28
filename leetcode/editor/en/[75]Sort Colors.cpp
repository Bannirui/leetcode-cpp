//Given an array nums with n objects colored red, white, or blue, sort them in-
//place so that objects of the same color are adjacent, with the colors in the 
//order red, white, and blue. 
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and 
//blue, respectively. 
//
// You must solve this problem without using the library's sort function. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
// 
//
// Example 2: 
//
// 
//Input: nums = [2,0,1]
//Output: [0,1,2]
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 300 
// nums[i] is either 0, 1, or 2. 
// 
//
// 
// Follow up: Could you come up with a one-pass algorithm using only constant 
//extra space? 
//
// Related TopicsArray | Two Pointers | Sorting 
//
// 👍 21232, 👎 756bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){return;}
        // [0...lo] [1 i...] [hi...n-1]
        int lo=-1,hi=n;
        int i=0;
        while(i<hi){
            if(nums[i]==0){
                ++lo;
                std::swap(nums[lo],nums[i]);
                // 换过来的肯定是1
                ++i;
            }else if(nums[i]==1){
                ++i;
            }else{
                --hi;
                std::swap(nums[i],nums[hi]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
