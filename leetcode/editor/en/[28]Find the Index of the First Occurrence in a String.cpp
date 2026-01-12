//Given two strings needle and haystack, return the index of the first 
//occurrence of needle in haystack, or -1 if needle is not part of haystack. 
//
// 
// Example 1: 
//
// 
//Input: haystack = "sadbutsad", needle = "sad"
//Output: 0
//Explanation: "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
// 
//
// Example 2: 
//
// 
//Input: haystack = "leetcode", needle = "leeto"
//Output: -1
//Explanation: "leeto" did not occur in "leetcode", so we return -1.
// 
//
// 
// Constraints: 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack and needle consist of only lowercase English characters. 
// 
//
// Related TopicsTwo Pointers | String | String Matching 
//
// 👍 7356, 👎 558bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strStr(string haystack, string needle) {
        //Input: haystack = "sadbutsad", needle = "sad"
        //Output: 0
        //Explanation: "sad" occurs at index 0 and 6.
        //The first occurrence is at index 0, so we return 0.
        int i=0; // [i...j]
        int haystackLen=haystack.size();
        while(i<haystackLen){
            int k=i;
            int j=0;
            int needleLen=needle.size();
            while(k<haystackLen && j<needleLen && haystack[k]==needle[j]){
                k++;
                j++;
            }
            if(j==needleLen){return i;}
            if(k==haystackLen) { return -1; }
            i++;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
