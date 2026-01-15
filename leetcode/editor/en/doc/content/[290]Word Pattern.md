<p>Given a <code>pattern</code> and a string <code>s</code>, find if <code>s</code>&nbsp;follows the same pattern.</p>

<p>Here <b>follow</b> means a full match, such that there is a bijection between a letter in <code>pattern</code> and a <b>non-empty</b> word in <code>s</code>. Specifically:</p>

<ul> 
 <li>Each letter in <code>pattern</code> maps to <strong>exactly</strong> one unique word in <code>s</code>.</li> 
 <li>Each unique word in <code>s</code> maps to <strong>exactly</strong> one letter in <code>pattern</code>.</li> 
 <li>No two letters map to the same word, and no two words map to the same letter.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">pattern = "abba", s = "dog cat cat dog"</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>The bijection can be established as:</p>

<ul> 
 <li><code>'a'</code> maps to <code>"dog"</code>.</li> 
 <li><code>'b'</code> maps to <code>"cat"</code>.</li> 
</ul>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">pattern = "abba", s = "dog cat cat fish"</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">pattern = "aaaa", s = "dog cat cat dog"</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= pattern.length &lt;= 300</code></li> 
 <li><code>pattern</code> contains only lower-case English letters.</li> 
 <li><code>1 &lt;= s.length &lt;= 3000</code></li> 
 <li><code>s</code> contains only lowercase English letters and spaces <code>' '</code>.</li> 
 <li><code>s</code> <strong>does not contain</strong> any leading or trailing spaces.</li> 
 <li>All the words in <code>s</code> are separated by a <strong>single space</strong>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Hash Table | String</details><br>

<div>👍 7889, 👎 1134<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

原谅我一开始都没理解这题啥意思，原来就是类似我们小学学的叠词，比方说 AABB -> 大大方方，ABAB -> 打听打听。题目其实就是问你 `s` 是否符合 `pattern` 的叠词模式。

那思路就很简单了，利用哈希表，把 `pattern` 中的每个叠词模式字符在 `s` 中的对应单词记录下来，就能判断 `s` 是否匹配 `pattern` 的模式了，比较简单。

另外，这道题的进阶题目 [$ ✨291. 单词规律 II](/problems/word-pattern-ii/) 比较有意思，考察暴力穷举算法。

**详细题解**：
  - [【练习】哈希表更多习题](https://labuladong.online/algo/problem-set/hash-table/)

</div>





<div id="solution">

## 解法代码



<div class="tab-panel"><div class="tab-nav">
<button data-tab-item="cpp" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">cpp🤖</button>

<button data-tab-item="python" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">python🤖</button>

<button data-tab-item="java" class="tab-nav-button btn active" data-tab-group="default" onclick="switchTab(this)">java🟢</button>

<button data-tab-item="go" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">go🤖</button>

<button data-tab-item="javascript" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">javascript🤖</button>
</div><div class="tab-content">
<div data-tab-item="cpp" class="tab-item " data-tab-group="default"><div class="highlight">

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        size_t start = 0;
        size_t end = s.find(' ');
        while (end != string::npos) {
            words.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(' ', start);
        }
        words.push_back(s.substr(start));
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // 记录 pattern 字符到单词的映射
        unordered_map<char, string> patternToWord;
        // 记录那些已经有 pattern 对应的单词
        unordered_set<string> wordSet;
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string word = words[i];
            if (patternToWord.find(c) == patternToWord.end()) {
                if (wordSet.find(word) != wordSet.end()) {
                    // 这个单词以前已经有其他模式字符对应了
                    return false;
                }
                // 添加 c -> word 的映射
                patternToWord[c] = word;
            } else {
                // 这个 pattern 字符已经出现过，确保和之前对应的单词相同
                if (patternToWord[c] != word) {
                    return false;
                }
            }
            // 这个单词已经有模式字符对应
            wordSet.insert(word);
        }
        return true;
    }
};

class Solution2 {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        size_t start = 0;
        size_t end = s.find(' ');
        while (end != string::npos) {
            words.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(' ', start);
        }
        words.push_back(s.substr(start));
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // 记录 pattern 字符到单词的映射
        unordered_map<string, char> wordToPattern;
        // 记录那些已经有 pattern 对应的单词
        unordered_set<char> patternCharSet;
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string word = words[i];
            if (wordToPattern.find(word) == wordToPattern.end()) {
                // 当前这个单词还没有对应的模式字符
                if (patternCharSet.find(c) != patternCharSet.end()) {
                    // 对应的模式字符之前已经对应了其他单词
                    return false;
                }
                // 添加 word -> c 的映射
                wordToPattern[word] = c;
            } else {
                // 这个单词之前已经出现过，确保当前单词和之前对应的模式字符相同
                if (wordToPattern[word] != c) {
                    return false;
                }
            }
            patternCharSet.insert(c);
        }
        return true;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        # 记录 pattern 字符到单词的映射
        pattern_to_word = {}
        # 记录那些已经有 pattern 对应的单词
        word_set = set()

        for i, c in enumerate(pattern):
            word = words[i]
            if c not in pattern_to_word:
                if word in word_set:
                    # 这个单词以前已经有其他模式字符对应了
                    return False
                # 添加 c -> word 的映射
                pattern_to_word[c] = word
            else:
                # 这个 pattern 字符已经出现过，确保和之前对应的单词相同
                if pattern_to_word[c] != word:
                    return False
            # 这个单词已经有模式字符对应
            word_set.add(word)
        return True


class Solution2:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        # 记录 pattern 字符到单词的映射
        word_to_pattern = {}
        pattern_char_set = set()

        for i, c in enumerate(pattern):
            word = words[i]
            if word not in word_to_pattern:
                # 当前这个单词还没有对应的模式字符
                if c in pattern_char_set:
                    # 对应的模式字符之前已经对应了其他单词
                    return False
                # 添加 word -> c 的映射
                word_to_pattern[word] = c
            else:
                # 这个单词之前已经出现过，确保当前单词和之前对应的模式字符相同
                if word_to_pattern[word] != c:
                    return False
            pattern_char_set.add(c)
        return True
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        // 记录 pattern 字符到单词的映射
        HashMap<Character, String> patternToWord = new HashMap<>();
        // 记录那些已经有 pattern 对应的单词
        HashSet<String> wordSet = new HashSet<>();

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String word = words[i];
            if (!patternToWord.containsKey(c)) {
                if (wordSet.contains(word)) {
                    // 这个单词以前已经有其他模式字符对应了
                    return false;
                }
                // 添加 c -> word 的映射
                patternToWord.put(c, word);
            } else {
                // 这个 pattern 字符已经出现过，确保和之前对应的单词相同
                if (!patternToWord.get(c).equals(word)) {
                    return false;
                }
            }
            // 这个单词已经有模式字符对应
            wordSet.add(word);
        }
        return true;
    }
}



class Solution2 {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) {
            return false;
        }
        // 记录 pattern 字符到单词的映射
        HashMap<String, Character> wordToPattern = new HashMap<>();
        HashSet<Character> patternCharSet = new HashSet<>();

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String word = words[i];
            if (!wordToPattern.containsKey(word)) {
                // 当前这个单词还没有对应的模式字符
                if (patternCharSet.contains(c)) {
                    // 对应的模式字符之前已经对应了其他单词
                    return false;
                }
                // 添加 word -> c 的映射
                wordToPattern.put(word, c);
            } else {
                // 这个单词之前已经出现过，确保当前单词和之前对应的模式字符相同
                if (!wordToPattern.get(word).equals(c)) {
                    return false;
                }
            }
            patternCharSet.add(c);
        }
        return true;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func wordPattern(pattern string, s string) bool {
    words := strings.Split(s, " ")
    if len(pattern) != len(words) {
        return false
    }
    // 记录 pattern 字符到单词的映射
    patternToWord := make(map[rune]string)
    // 记录那些已经有 pattern 对应的单词
    wordSet := make(map[string]bool)

    for i, c := range pattern {
        word := words[i]
        if _, ok := patternToWord[c]; !ok {
            if wordSet[word] {
                // 这个单词以前已经有其他模式字符对应了
                return false
            }
            // 添加 c -> word 的映射
            patternToWord[c] = word
        } else {
            // 这个 pattern 字符已经出现过，确保和之前对应的单词相同
            if patternToWord[c] != word {
                return false
            }
        }
        // 这个单词已经有模式字符对应
        wordSet[word] = true
    }
    return true
}

func wordPattern2(pattern string, s string) bool {
    words := strings.Split(s, " ")
    if len(pattern) != len(words) {
        return false
    }
    // 记录 pattern 字符到单词的映射
    wordToPattern := make(map[string]rune)
    patternCharSet := make(map[rune]bool)

    for i, c := range pattern {
        word := words[i]
        if _, ok := wordToPattern[word]; !ok {
            // 当前这个单词还没有对应的模式字符
            if patternCharSet[c] {
                // 对应的模式字符之前已经对应了其他单词
                return false
            }
            // 添加 word -> c 的映射
            wordToPattern[word] = c
        } else {
            // 这个单词之前已经出现过，确保当前单词和之前对应的模式字符相同
            if wordToPattern[word] != c {
                return false
            }
        }
        patternCharSet[c] = true
    }
    return true
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var wordPattern = function(pattern, s) {
    const words = s.split(" ");
    if (pattern.length !== words.length) {
        return false;
    }
    // 记录 pattern 字符到单词的映射
    const patternToWord = new Map();
    // 记录那些已经有 pattern 对应的单词
    const wordSet = new Set();

    for (let i = 0; i < pattern.length; i++) {
        const c = pattern[i];
        const word = words[i];
        if (!patternToWord.has(c)) {
            if (wordSet.has(word)) {
                // 这个单词以前已经有其他模式字符对应了
                return false;
            }
            // 添加 c -> word 的映射
            patternToWord.set(c, word);
        } else {
            // 这个 pattern 字符已经出现过，确保和之前对应的单词相同
            if (patternToWord.get(c) !== word) {
                return false;
            }
        }
        // 这个单词已经有模式字符对应
        wordSet.add(word);
    }
    return true;
};

var wordPattern2 = function(pattern, s) {
    const words = s.split(" ");
    if (pattern.length !== words.length) {
        return false;
    }
    // 记录 pattern 字符到单词的映射
    const wordToPattern = new Map();
    // 记录那些已经有模式字符对应的单词
    const patternCharSet = new Set();

    for (let i = 0; i < pattern.length; i++) {
        const c = pattern[i];
        const word = words[i];
        if (!wordToPattern.has(word)) {
            // 当前这个单词还没有对应的模式字符
            if (patternCharSet.has(c)) {
                // 对应的模式字符之前已经对应了其他单词
                return false;
            }
            // 添加 word -> c 的映射
            wordToPattern.set(word, c);
        } else {
            // 这个单词之前已经出现过，确保当前单词和之前对应的模式字符相同
            if (wordToPattern.get(word) !== c) {
                return false;
            }
        }
        patternCharSet.add(c);
    }
    return true;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>👾👾 算法可视化 👾👾</strong></summary><div id="data_word-pattern"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_word-pattern"></div></div>
</details><hr /><br />

</div>
</details>
</div>

