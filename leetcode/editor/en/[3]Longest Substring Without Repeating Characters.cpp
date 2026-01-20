//Given a string s, find the length of the longest substring without duplicate 
//characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3. Note that "bca" and 
//"cab" are also correct answers.
// 
//
// Example 2: 
//
// 
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
// 
//
// Example 3: 
//
// 
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a 
//substring.
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s consists of English letters, digits, symbols and spaces. 
// 
//
// Related TopicsHash Table | String | Sliding Window 
//
// 👍 44125, 👎 2162bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 测试用例:"dvdf"
        int ret=0;
        int n=s.size();
        // [i...j]
        int i=0,j=0;
        std::vector<int> cnt(256,0);
        while(j<n){
            if(cnt[s[j]-'\0']==0){
                // 扩
                ret=std::max(ret,j-i+1);
                ++cnt[s[j]-'\0'];
                ++j;
            }else{
                // 缩
                while(i<=j && cnt[s[j]-'\0']!=0){
                    --cnt[s[i]-'\0'];
                    ++i;
                }
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
