//You have n coins and you want to build a staircase with these coins. The 
//staircase consists of k rows where the iᵗʰ row has exactly i coins. The last row of 
//the staircase may be incomplete. 
//
// Given the integer n, return the number of complete rows of the staircase you 
//will build. 
//
// 
// Example 1: 
// 
// 
//Input: n = 5
//Output: 2
//Explanation: Because the 3ʳᵈ row is incomplete, we return 2.
// 
//
// Example 2: 
// 
// 
//Input: n = 8
//Output: 3
//Explanation: Because the 4ᵗʰ row is incomplete, we return 3.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
//
// Related TopicsMath | Binary Search 
//
// 👍 4277, 👎 1373bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // sum[1...n]
    long long sum(int n){
        return ((long long)(n*(long long)(n+1)))/2;
    }
public:
    int arrangeCoins(int n) {
        // [1...n]
        int lo=1,hi=n;
        int ret=0;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            long long s=this->sum(mid);
            if(s==n){return mid;}
            if(s<=n){
                ret=mid;
                lo=mid+1;
            }else{hi=mid-1;}
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
