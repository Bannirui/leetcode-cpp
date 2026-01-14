//Given an integer array nums, return the third distinct maximum number in this 
//array. If the third maximum does not exist, return the maximum number. 
//
// 
// Example 1: 
//
// 
//Input: nums = [3,2,1]
//Output: 1
//Explanation:
//The first distinct maximum is 3.
//The second distinct maximum is 2.
//The third distinct maximum is 1.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2]
//Output: 2
//Explanation:
//The first distinct maximum is 2.
//The second distinct maximum is 1.
//The third distinct maximum does not exist, so the maximum (2) is returned 
//instead.
// 
//
// Example 3: 
//
// 
//Input: nums = [2,2,3,1]
//Output: 1
//Explanation:
//The first distinct maximum is 3.
//The second distinct maximum is 2 (both 2's are counted together since they 
//have the same value).
//The third distinct maximum is 1.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
//
// 
//Follow up: Can you find an 
//O(n) solution?
//
// Related TopicsArray | Sorting 
//
// 👍 3448, 👎 3473bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.empty()){throw std::invalid_argument("nums size");}
        // 小根堆
        std::priority_queue<int,std::vector<int>,std::greater<int>> q;
        std::unordered_set<int> set;
        for(auto& x:nums){
            if(set.count(x)){continue;}
            q.push(x);
            set.insert(x);
            if(q.size()>3){q.pop();}
        }
        if(q.size()<3){
            while(q.size()>1){q.pop();}
        }
        return q.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
