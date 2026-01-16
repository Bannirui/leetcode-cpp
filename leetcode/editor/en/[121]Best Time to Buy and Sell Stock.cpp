//You are given an array prices where prices[i] is the price of a given stock 
//on the iᵗʰ day. 
//
// You want to maximize your profit by choosing a single day to buy one stock 
//and choosing a different day in the future to sell that stock. 
//
// Return the maximum profit you can achieve from this transaction. If you 
//cannot achieve any profit, return 0. 
//
// 
// Example 1: 
//
// 
//Input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 
//6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you 
//must buy before you sell.
// 
//
// Example 2: 
//
// 
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transactions are done and the max profit = 0.
// 
//
// 
// Constraints: 
//
// 
// 1 <= prices.length <= 10⁵ 
// 0 <= prices[i] <= 10⁴ 
// 
//
// Related TopicsArray | Dynamic Programming 
//
// 👍 34948, 👎 1386bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
        // dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
        //            =max(dp[i-1][k][1],-prices[i])
        // k=1
        int n=prices.size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(2,0));
        // base
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;++i){
            dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=std::max(dp[i-1][1],-prices[i]);
        }
        return dp[n-1][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
