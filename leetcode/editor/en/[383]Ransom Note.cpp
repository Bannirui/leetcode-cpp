//Given two strings ransomNote and magazine, return true if ransomNote can be 
//constructed by using the letters from magazine and false otherwise. 
//
// Each letter in magazine can only be used once in ransomNote. 
//
// 
// Example 1: 
// Input: ransomNote = "a", magazine = "b"
//Output: false
// 
// Example 2: 
// Input: ransomNote = "aa", magazine = "ab"
//Output: false
// 
// Example 3: 
// Input: ransomNote = "aa", magazine = "aab"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= ransomNote.length, magazine.length <= 10⁵ 
// ransomNote and magazine consist of lowercase English letters. 
// 
//
// Related TopicsHash Table | String | Counting 
//
// 👍 5591, 👎 541bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // ransomNote and magazine consist of lowercase English letters.
        std::vector<int> cnt(26,0);
        for(auto& ch:magazine){++cnt[ch-'a'];}
        for(auto& ch:ransomNote){
            int i=ch-'a';
            if(--cnt[i]<0){return false;}
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
