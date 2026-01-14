//Given a string s, reverse only all the vowels in the string and return it. 
//
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both 
//lower and upper cases, more than once. 
//
// 
// Example 1: 
//
// 
// Input: s = "IceCreAm" 
// 
//
// Output: "AceCreIm" 
//
// Explanation: 
//
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes 
//"AceCreIm". 
//
// Example 2: 
//
// 
// Input: s = "leetcode" 
// 
//
// Output: "leotcede" 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s consist of printable ASCII characters. 
// 
//
// Related TopicsTwo Pointers | String 
//
// 👍 5260, 👎 2850bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseVowels(string s) {
        std::unordered_set<char> set{'a','A','e','E','i','I','o','O','u','U'};
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j && !set.count(s[i])){++i;}
            while(i<j && !set.count(s[j])){--j;}
            if(i<j){
                std::swap(s[i],s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
