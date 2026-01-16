//Given an integer array nums, return true if any value appears at least twice 
//in the array, and return false if every element is distinct. 
//
// 
// Example 1: 
//
// 
// Input: nums = [1,2,3,1] 
// 
//
// Output: true 
//
// Explanation: 
//
// The element 1 occurs at the indices 0 and 3. 
//
// Example 2: 
//
// 
// Input: nums = [1,2,3,4] 
// 
//
// Output: false 
//
// Explanation: 
//
// All elements are distinct. 
//
// Example 3: 
//
// 
// Input: nums = [1,1,1,3,3,4,3,2,4,2] 
// 
//
// Output: true 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
//
// Related TopicsArray | Hash Table | Sorting 
//
// 👍 13626, 👎 1352bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for(auto& x:nums){
            if(set.count(x)){return true;}
            set.insert(x);
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
