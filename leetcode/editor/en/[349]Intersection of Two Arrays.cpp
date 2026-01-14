//Given two integer arrays nums1 and nums2, return an array of their 
//intersection. Each element in the result must be unique and you may return the result in 
//any order. 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
// 
//
// Example 2: 
//
// 
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums1.length, nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 1000 
// 
//
// Related TopicsArray | Hash Table | Two Pointers | Binary Search | Sorting 
//
// 👍 6780, 👎 2339bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        //Output: [9,4]
        //Explanation: [4,9] is also accepted.
        std::unordered_set<int> set1(nums1.cbegin(),nums1.cend());
        std::unordered_set<int> set2(nums2.cbegin(),nums2.cend());
        std::vector<int> ret;
        for(auto& x:set1){
            if(set2.count(x)){ret.push_back(x);}
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
