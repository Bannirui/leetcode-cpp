<p>Write a function to find the longest common prefix string amongst an array of strings.</p>

<p>If there is no common prefix, return an empty string <code>""</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = ["flower","flow","flight"]
<strong>Output:</strong> "fl"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = ["dog","racecar","car"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> There is no common prefix among the input strings.
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= strs.length &lt;= 200</code></li> 
 <li><code>0 &lt;= strs[i].length &lt;= 200</code></li> 
 <li><code>strs[i]</code> consists of only lowercase English letters if it is non-empty.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Array | String | Trie</details><br>

<div>👍 20706, 👎 4875<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这个题没什么难度，你把字符串列表看成一个二维数组，然后用一个嵌套 for 循环计算这个二维数组前面有多少列的元素完全相同即可。

如果硬要上点难度的话，你可以考虑用我在 [前缀树算法模板及原理](https://labuladong.online/algo/data-structure-basic/trie-map-basic/) 中讲过的前缀树结构，把这些字符串转化成前缀树来计算一下公共前缀。

**详细题解**：
  - [【练习】数组双指针经典习题](https://labuladong.online/algo/problem-set/array-two-pointers/)

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

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        // 以第一行的列数为基准
        int n = strs[0].length();
        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                string thisStr = strs[row], prevStr = strs[row - 1];
                // 判断每个字符串的 col 索引是否都相同
                if (col >= thisStr.length() || col >= prevStr.length() ||
                    thisStr[col] != prevStr[col]) {
                    // 发现不匹配的字符，只有 strs[row][0..col-1] 是公共前缀
                    return strs[row].substr(0, col);
                }
            }
        }
        return strs[0];
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        m = len(strs)
        # 以第一行的列数为基准
        n = len(strs[0])
        for col in range(n):
            for row in range(1, m):
                thisStr, prevStr = strs[row], strs[row - 1]
                # 判断每个字符串的 col 索引是否都相同
                if col >= len(thisStr) or col >= len(prevStr) or thisStr[col] != prevStr[col]:
                    # 发现不匹配的字符，只有 strs[row][0..col-1] 是公共前缀
                    return strs[row][:col]
        return strs[0]
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int m = strs.length;
        // 以第一行的列数为基准
        int n = strs[0].length();
        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                String thisStr = strs[row], prevStr = strs[row - 1];
                // 判断每个字符串的 col 索引是否都相同
                if (col >= thisStr.length() || col >= prevStr.length() ||
                        thisStr.charAt(col) != prevStr.charAt(col)) {
                    // 发现不匹配的字符，只有 strs[row][0..col-1] 是公共前缀
                    return strs[row].substring(0, col);
                }
            }
        }
        return strs[0];
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func longestCommonPrefix(strs []string) string {
    m := len(strs)
    // 以第一行的列数为基准
    n := len(strs[0])
    for col := 0; col < n; col++ {
        for row := 1; row < m; row++ {
            thisStr, prevStr := strs[row], strs[row-1]
            // 判断每个字符串的 col 索引是否都相同
            if col >= len(thisStr) || col >= len(prevStr) || thisStr[col] != prevStr[col] {
                // 发现不匹配的字符，只有 strs[row][0..col-1] 是公共前缀
                return strs[row][:col]
            }
        }
    }
    return strs[0]
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var longestCommonPrefix = function(strs) {
    let m = strs.length;
    // 以第一行的列数为基准
    let n = strs[0].length;
    for (let col = 0; col < n; col++) {
        for (let row = 1; row < m; row++) {
            let thisStr = strs[row], prevStr = strs[row - 1];
            // 判断每个字符串的 col 索引是否都相同
            if (col >= thisStr.length || col >= prevStr.length ||
                    thisStr.charAt(col) !== prevStr.charAt(col)) {
                // 发现不匹配的字符，只有 strs[row][0..col-1] 是公共前缀
                return strs[row].substring(0, col);
            }
        }
    }
    return strs[0];
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🍭🍭 算法可视化 🍭🍭</strong></summary><div id="data_longest-common-prefix"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_longest-common-prefix"></div></div>
</details><hr /><br />

</div>
</details>
</div>

