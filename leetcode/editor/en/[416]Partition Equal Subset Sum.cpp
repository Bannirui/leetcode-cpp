//Given an integer array nums, return true if you can partition the array into 
//two subsets such that the sum of the elements in both subsets is equal or false 
//otherwise. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,5,11,5]
//Output: true
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,5]
//Output: false
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
//
// Related TopicsArray | Dynamic Programming 
//
// 👍 13679, 👎 296bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //Input: nums = [1,5,11,5]
        //Output: true
        //Explanation: The array can be partitioned as [1, 5, 5] and [11].
        int sum=std::accumulate(nums.cbegin(),nums.cend(),0);
        if(sum&1){return false;}
        // 在nums[0...]找和为1/2 sum
        int target=(sum>>1);
        for(auto& x:nums){
            if(x>target){return false;}
        }
        // dp[i][j]用nums前i个数求和j
        int sz=nums.size();
        int rows=sz+1;
        int cols=target+1;
        std::vector<std::vector<bool>> dp(rows,std::vector<bool>(cols,false));
        // base
        dp[0][0]=true;
        for(int i=1;i<rows;i++) {dp[i][0]=true;}
        for(int j=1;j<cols;j++){dp[0][j]=false;}
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0){
                    dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[sz][target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
