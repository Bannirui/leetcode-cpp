//Given an integer array nums and an integer k, return true if there are two 
//distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <
//= k. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,1], k = 3
//Output: true
// 
//
// Example 2: 
//
// 
//Input: nums = [1,0,1,1], k = 1
//Output: true
// 
//
// Example 3: 
//
// 
//Input: nums = [1,2,3,1,2,3], k = 2
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// 0 <= k <= 10⁵ 
// 
//
// Related TopicsArray | Hash Table | Sliding Window 
//
// 👍 7278, 👎 3299bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // x i->i-x=k->x=i-k
        std::unordered_map<int,int> cnt;
        int n=nums.size();
        for(int i=0;i<n;++i){
            int x=i-(k+1);
            if(x>=0){--cnt[nums[x]];}
            if(cnt.count(nums[i])){
                if(++cnt[nums[i]]>1){return true;}
            }else{
                cnt[nums[i]]=1;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
