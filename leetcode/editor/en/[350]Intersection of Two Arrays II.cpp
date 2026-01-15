//Given two integer arrays nums1 and nums2, return an array of their 
//intersection. Each element in the result must appear as many times as it shows in both 
//arrays and you may return the result in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
// 
//
// Example 2: 
//
// 
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Explanation: [9,4] is also accepted.
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
// 
// Follow up: 
//
// 
// What if the given array is already sorted? How would you optimize your 
//algorithm? 
// What if nums1's size is small compared to nums2's size? Which algorithm is 
//better? 
// What if elements of nums2 are stored on disk, and the memory is limited such 
//that you cannot load all elements into the memory at once? 
// 
//
// Related TopicsArray | Hash Table | Two Pointers | Binary Search | Sorting 
//
// 👍 8116, 👎 1009bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 0 <= nums1[i], nums2[i] <= 1000
        std::vector<int> ret;
        std::vector<int> cnt1(1001,0);
        std::vector<int> cnt2(1001,0);
        for(auto& x:nums1){++cnt1[x];}
        for(auto& x:nums2){++cnt2[x];}
        for(int i=0;i<1001;++i){
            if(cnt1[i]>0 && cnt2[i]>0){
                int min=std::min(cnt1[i],cnt2[i]);
                for(int j=0;j<min;++j){
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
