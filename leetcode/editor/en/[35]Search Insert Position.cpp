//Given a sorted array of distinct integers and a target value, return the 
//index if the target is found. If not, return the index where it would be if it were 
//inserted in order. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,5,6], target = 5
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: nums = [1,3,5,6], target = 2
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: nums = [1,3,5,6], target = 7
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums contains distinct values sorted in ascending order. 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related TopicsArray | Binary Search 
//
// 👍 18395, 👎 877bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Input: nums = [1,3,5,6], target = 2
        //Output: 1
        //Input: nums = [1,3,5,6], target = 5
        //Output: 2
        int n=nums.size();
        int lo=0,hi=n-1;
        int ret=n;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            if(nums[mid]==target){return mid;}
            else if(nums[mid]<target){
				lo=mid+1;
            }
            else{
				ret=mid;
                hi=mid-1;
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
