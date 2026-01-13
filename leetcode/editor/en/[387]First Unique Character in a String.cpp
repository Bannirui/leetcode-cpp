//Given a string s, find the first non-repeating character in it and return its 
//index. If it does not exist, return -1. 
//
// 
// Example 1: 
//
// 
// Input: s = "leetcode" 
// 
//
// Output: 0 
//
// Explanation: 
//
// The character 'l' at index 0 is the first character that does not occur at 
//any other index. 
//
// Example 2: 
//
// 
// Input: s = "loveleetcode" 
// 
//
// Output: 2 
//
// Example 3: 
//
// 
// Input: s = "aabb" 
// 
//
// Output: -1 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s consists of only lowercase English letters. 
// 
//
// Related TopicsHash Table | String | Queue | Counting 
//
// 👍 9631, 👎 328bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstUniqChar(string s) {
        // Input: s = "loveleetcode"
        // Output: 2
        // s consists of only lowercase English letters.
        std::vector<int> cnt(26,0);
        // 统计
        for(auto& ch:s){++cnt[ch-'a'];}
        for(int i=0;i<s.size();++i){
            if(cnt[s[i]-'a']==1){return i;}
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
