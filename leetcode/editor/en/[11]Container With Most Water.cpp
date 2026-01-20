//You are given an integer array height of length n. There are n vertical lines 
//drawn such that the two endpoints of the iᵗʰ line are (i, 0) and (i, height[i]).
// 
//
// Find two lines that together with the x-axis form a container, such that the 
//container contains the most water. 
//
// Return the maximum amount of water a container can store. 
//
// Notice that you may not slant the container. 
//
// 
// Example 1: 
// 
// 
//Input: height = [1,8,6,2,5,4,8,3,7]
//Output: 49
//Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,
//3,7]. In this case, the max area of water (blue section) the container can 
//contain is 49.
// 
//
// Example 2: 
//
// 
//Input: height = [1,1]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// n == height.length 
// 2 <= n <= 10⁵ 
// 0 <= height[i] <= 10⁴ 
// 
//
// Related TopicsArray | Two Pointers | Greedy 
//
// 👍 33487, 👎 2153bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& height) {
        //Input: height = [1,8,6,2,5,4,8,3,7]
        //Output: 49
        int n=height.size();
        int lo=0,hi=n-1;
        int ret=0;
        while(lo<hi){
            int w=hi-lo;
            int h=std::min(height[lo],height[hi]);
            int cur=w*h;
            if(cur>ret){ret=cur;}
            if(height[lo]<height[hi]){++lo;}
            else{--hi;}
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
