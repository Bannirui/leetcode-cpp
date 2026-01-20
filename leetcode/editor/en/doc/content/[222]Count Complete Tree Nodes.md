<p>Given the <code>root</code> of a <strong>complete</strong> binary tree, return the number of the nodes in the tree.</p>

<p>According to <strong><a href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees" target="_blank">Wikipedia</a></strong>, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between <code>1</code> and <code>2<sup>h</sup></code> nodes inclusive at the last level <code>h</code>.</p>

<p>Design an algorithm that runs in less than&nbsp;<code data-stringify-type="code">O(n)</code>&nbsp;time complexity.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/complete.jpg" style="width: 372px; height: 302px;" /> 
<pre>
<strong>Input:</strong> root = [1,2,3,4,5,6]
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li>The number of nodes in the tree is in the range <code>[0, 5 * 10<sup>4</sup>]</code>.</li> 
 <li><code>0 &lt;= Node.val &lt;= 5 * 10<sup>4</sup></code></li> 
 <li>The tree is guaranteed to be <strong>complete</strong>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Binary Search | Bit Manipulation | Tree | Binary Tree</details><br>

<div>👍 9385, 👎 603<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**



<p><strong><a href="https://labuladong.online/algo/data-structure/count-complete-tree-nodes/" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

一棵完全二叉树的两棵子树，至少有一棵是满二叉树：

![](https://labuladong.online/algo/images/complete_tree/1.jpg)

计算满二叉树的节点个数不用一个个节点去数，可以直接通过树高算出来，这也是这道题提高效率的关键点。

**详细题解**：
  - [拓展：如何计算完全二叉树的节点数](https://labuladong.online/algo/data-structure/count-complete-tree-nodes/)

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
    int countNodes(TreeNode* root) {
        TreeNode* l = root, * r = root;
        // 沿最左侧和最右侧分别计算高度
        int hl = 0, hr = 0;
        while (l != nullptr) {
            l = l->left;
            hl++;
        }
        while (r != nullptr) {
            r = r->right;
            hr++;
        }
        // 如果左右侧计算的高度相同，则是一棵满二叉树
        if (hl == hr) {
            return pow(2, hl) - 1;
        }
        // 如果左右侧的高度不同，则按照普通二叉树的逻辑计算
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        l = root
        r = root
        hl = 0
        hr = 0
        # 沿最左侧和最右侧分别计算高度
        while l is not None:
            l = l.left
            hl += 1
        while r is not None:
            r = r.right
            hr += 1
        # 如果左右侧计算的高度相同，则是一棵满二叉树
        if hl == hr:
            return pow(2, hl) - 1
        # 如果左右侧的高度不同，则按照普通二叉树的逻辑计算
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public int countNodes(TreeNode root) {
        TreeNode l = root, r = root;
        // 记录左、右子树的高度
        int hl = 0, hr = 0;
        while (l != null) {
            l = l.left;
            hl++;
        }
        while (r != null) {
            r = r.right;
            hr++;
        }
        // 如果左右子树的高度相同，则是一棵满二叉树
        if (hl == hr) {
            return (int) Math.pow(2, hl) - 1;
        }
        // 如果左右高度不同，则按照普通二叉树的逻辑计算
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func countNodes(root *TreeNode) int {
    l, r := root, root
    // 沿最左侧和最右侧分别计算高度
    hl, hr := 0, 0
    for l != nil {
        l = l.Left
        hl++
    }
    for r != nil {
        r = r.Right
        hr++
    }
    // 如果左右侧计算的高度相同，则是一棵满二叉树
    if hl == hr {
        return int(math.Pow(2, float64(hl))) - 1
    }
    // 如果左右侧的高度不同，则按照普通二叉树的逻辑计算
    return 1 + countNodes(root.Left) + countNodes(root.Right)
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var countNodes = function(root) {
    let l = root, r = root;
    // 沿最左侧和最右侧分别计算高度
    let hl = 0, hr = 0;
    while (l !== null) {
        l = l.left;
        hl++;
    }
    while (r !== null) {
        r = r.right;
        hr++;
    }
    // 如果左右侧计算的高度相同，则是一棵满二叉树
    if (hl === hr) {
        return Math.pow(2, hl) - 1;
    }
    // 如果左右侧的高度不同，则按照普通二叉树的逻辑计算
    return 1 + countNodes(root.left) + countNodes(root.right);
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🎃🎃 算法可视化 🎃🎃</strong></summary><div id="data_count-complete-tree-nodes"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_count-complete-tree-nodes"></div></div>
</details><hr /><br />

</div>
</details>
</div>

