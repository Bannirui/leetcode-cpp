<p>Given an array <code>nums</code> containing <code>n</code> distinct numbers in the range <code>[0, n]</code>, return <em>the only number in the range that is missing from the array.</em></p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">nums = [3,0,1]</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><code>n = 3</code> since there are 3 numbers, so all numbers are in the range <code>[0,3]</code>. 2 is the missing number in the range since it does not appear in <code>nums</code>.</p>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">nums = [0,1]</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><code>n = 2</code> since there are 2 numbers, so all numbers are in the range <code>[0,2]</code>. 2 is the missing number in the range since it does not appear in <code>nums</code>.</p>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">nums = [9,6,4,2,3,5,7,0,1]</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">8</span></p>

<p><strong>Explanation:</strong></p>

<p><code>n = 9</code> since there are 9 numbers, so all numbers are in the range <code>[0,9]</code>. 8 is the missing number in the range since it does not appear in <code>nums</code>.</p>

<div class="simple-translate-system-theme" id="simple-translate"> 
 <div> 
  <div class="simple-translate-button isShow" style="background-image: url(&quot;moz-extension://8a9ffb6b-7e69-4e93-aae1-436a1448eff6/icons/512.png&quot;); height: 22px; width: 22px; top: 318px; left: 36px;">
   &nbsp;
  </div> 
 </div>
</div>

<div class="simple-translate-panel " style="width: 300px; height: 200px; top: 0px; left: 0px; font-size: 13px;"> 
 <div class="simple-translate-result-wrapper" style="overflow: hidden;"> 
  <div class="simple-translate-move" draggable="true">
   &nbsp;
  </div> 
 </div>
</div>

<div class="simple-translate-result-contents"> 
 <p class="simple-translate-result" dir="auto">&nbsp;</p> 
</div>

<p class="simple-translate-candidate" dir="auto">&nbsp;</p>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == nums.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li> 
 <li><code>0 &lt;= nums[i] &lt;= n</code></li> 
 <li>All the numbers of <code>nums</code> are <strong>unique</strong>.</li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow up:</strong> Could you implement a solution using only <code>O(1)</code> extra space complexity and <code>O(n)</code> runtime complexity?</p>

<details><summary><strong>Related Topics</strong></summary>Array | Hash Table | Math | Binary Search | Bit Manipulation | Sorting</details><br>

<div>👍 13988, 👎 3458<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**



<p><strong><a href="https://labuladong.online/algo/frequency-interview/bitwise-operation/" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

假设 `nums = [0,3,1,4]`：

![](https://labuladong.online/algo/images/missing-elem/1.jpg)

我们先把索引补一位，然后让每个元素和自己相等的索引相对应：

![](https://labuladong.online/algo/images/missing-elem/2.jpg)

这样做了之后，就可以发现除了缺失元素之外，所有的索引和元素都组成一对儿了，现在如果把这个落单的索引 2 找出来，也就找到了缺失的那个元素。

如何找？只要把所有的元素和索引做异或运算，成对儿的数字都会消为 0，只有这个落单的元素会剩下。

**详细题解**：
  - [常用的位操作](https://labuladong.online/algo/frequency-interview/bitwise-operation/)

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

#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        // 先和新补的索引异或一下
        res ^= n;
        // 和其他的元素、索引做异或
        for (int i = 0; i < n; i++)
            res ^= i ^ nums[i];
        return res;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        # 先和新补的索引异或一下
        res ^= n
        # 和其他的元素、索引做异或
        for i in range(n):
            res ^= i ^ nums[i]
        return res
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int res = 0;
        // 先和新补的索引异或一下
        res ^= n;
        // 和其他的元素、索引做异或
        for (int i = 0; i < n; i++)
            res ^= i ^ nums[i];
        return res;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func missingNumber(nums []int) int {
    n := len(nums)
    res := 0
    // 先和新补的索引异或一下
    res ^= n
    // 和其他的元素、索引做异或
    for i := 0; i < n; i++ {
        res ^= i ^ nums[i]
    }
    return res
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var missingNumber = function(nums) {
    let n = nums.length;
    let res = 0;
    // 先和新补的索引异或一下
    res ^= n;
    // 和其他的元素、索引做异或
    for (let i = 0; i < n; i++)
        res ^= i ^ nums[i];
    return res;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🌈🌈 算法可视化 🌈🌈</strong></summary><div id="data_missing-number"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_missing-number"></div></div>
</details><hr /><br />

</div>
</details>
</div>

