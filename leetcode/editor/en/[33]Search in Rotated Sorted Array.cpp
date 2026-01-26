//There is an integer array nums sorted in ascending order (with distinct 
//values). 
//
// Prior to being passed to your function, nums is possibly left rotated at an 
//unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k],
// nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For 
//example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0
//,1,2]. 
//
// Given the array nums after the possible rotation and an integer target, 
//return the index of target if it is in nums, or -1 if it is not in nums. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
// 
// Example 2: 
// Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
// 
// Example 3: 
// Input: nums = [1], target = 0
//Output: -1
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5000 
// -10⁴ <= nums[i] <= 10⁴ 
// All values of nums are unique. 
// nums is an ascending array that is possibly rotated. 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related TopicsArray | Binary Search 
//
// 👍 29477, 👎 1784bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Input: nums = [4,5,6,7,0,1,2], target = 0
		//Output: 4
        // base
        int n=0;
        if((n=nums.size())==0){return -1;}
        // 前半段还是后半段
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(nums[mid]==target){return mid;}
            if(nums[mid]>=nums[0]){
                // 左边有序
                if(nums[lo]<=target && target<=nums[mid]){
                    // 折半
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }else{
                // 右边有序
                if(nums[mid]<=target && target<=nums[hi]){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
