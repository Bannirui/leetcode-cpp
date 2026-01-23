//Given an array of strings strs, group the anagrams together. You can return 
//the answer in any order. 
//
// 
// Example 1: 
//
// 
// Input: strs = ["eat","tea","tan","ate","nat","bat"] 
// 
//
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// Explanation: 
//
// 
// There is no string in strs that can be rearranged to form "bat". 
// The strings "nat" and "tan" are anagrams as they can be rearranged to form 
//each other. 
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged 
//to form each other. 
// 
//
// Example 2: 
//
// 
// Input: strs = [""] 
// 
//
// Output: [[""]] 
//
// Example 3: 
//
// 
// Input: strs = ["a"] 
// 
//
// Output: [["a"]] 
//
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] consists of lowercase English letters. 
// 
//
// Related TopicsArray | Hash Table | String | Sorting 
//
// 👍 21679, 👎 744bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Input: strs = ["eat","tea","tan","ate","nat","bat"]
        // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
        // strs[i] consists of lowercase English letters.
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(auto& str: strs){
            std::array<int,26> arr{0};
            for(int i=0,n=str.size();i<n;++i){
                ++arr[str[i]-'a'];
            }
            std::string tmpStr;
            for(int i=0;i<26;++i){
                tmpStr+=(std::to_string(arr[i])+"#");
            }
            if(map.count(tmpStr)){
                map[tmpStr].push_back(str);
            }else{
                std::vector<std::string> tmpVector;
                tmpVector.push_back(str);
                map[tmpStr]=tmpVector;
            }
        }
        std::vector<std::vector<std::string>> ret;
        for(auto it=map.begin();it!=map.end();++it){
            ret.push_back(it->second);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
