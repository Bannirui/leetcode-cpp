<p>Given a binary tree, find its minimum depth.</p>

<p>The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.</p>

<p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg" style="width: 432px; height: 302px;" /> 
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [2,null,3,null,4,null,5,null,6]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li>The number of nodes in the tree is in the range <code>[0, 10<sup>5</sup>]</code>.</li> 
 <li><code>-1000 &lt;= Node.val &lt;= 1000</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Tree | Depth-First Search | Breadth-First Search | Binary Tree</details><br>

<div>👍 7764, 👎 1360<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题可以同时运用两种思维，而且还可以用 BFS 层序遍历的方式求解，我会给出三种解法。

希望大家借助这道题仔细理解二叉树和 [BFS 算法](https://labuladong.online/algo/essential-technique/bfs-framework/)、[动态规划算法](https://labuladong.online/algo/essential-technique/dynamic-programming-framework/)、[回溯算法](https://labuladong.online/algo/essential-technique/backtrack-framework/) 的联系。

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

// 「遍历」的递归思路
class Solution {
private:
    int minDepthValue = INT_MAX;
    int currentDepth = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // 做选择：在进入节点时增加当前深度
        currentDepth++;

        // 如果当前节点是叶子节点，更新最小深度
        if (root->left == nullptr && root->right == nullptr) {
            minDepthValue = std::min(minDepthValue, currentDepth);
        }

        traverse(root->left);
        traverse(root->right);

        // 撤销选择：在离开节点时减少当前深度
        currentDepth--;
    }

public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        traverse(root);
        return minDepthValue;
    }
};

// 「分解问题」的递归思路
class Solution2 {
public:
    int minDepth(TreeNode* root) {
        // 基本情况：如果节点为空，返回深度为0
        if (root == nullptr) {
            return 0;
        }

        // 递归计算左子树的最小深度
        int leftDepth = minDepth(root->left);
        // 递归计算右子树的最小深度
        int rightDepth = minDepth(root->right);

        // 特殊情况处理：如果左子树为空，返回右子树的深度加1
        if (leftDepth == 0) {
            return rightDepth + 1;
        }
        // 特殊情况处理：如果右子树为空，返回左子树的深度加1
        if (rightDepth == 0) {
            return leftDepth + 1;
        }

        // 计算并返回最小深度：左右子树深度的最小值加1
        return std::min(leftDepth, rightDepth) + 1;
    }
};

// BFS 的思路
class Solution3 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        // root 本身就是一层，depth 初始化为 1
        int depth = 1;

        while (!q.empty()) {
            int sz = q.size();
            // 遍历当前层的节点
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                // 判断是否到达叶子结点
                if (cur->left == nullptr && cur->right == nullptr)
                    return depth;
                // 将下一层节点加入队列
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            // 这里增加步数
            depth++;
        }
        return depth;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

# 「遍历」的递归思路
class Solution:
    def __init__(self):
        self.minimumDepth = float('inf')
        self.currentDepth = 0

    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        self.traverse(root)
        return self.minimumDepth

    def traverse(self, root: TreeNode):
        if root is None:
            return

        # 做选择：在进入节点时增加当前深度
        self.currentDepth += 1

        # 如果当前节点是叶子节点，更新最小深度
        if root.left is None and root.right is None:
            self.minimumDepth = min(self.minimumDepth, self.currentDepth)

        self.traverse(root.left)
        self.traverse(root.right)

        # 撤销选择：在离开节点时减少当前深度
        self.currentDepth -= 1


# 「分解问题」的递归思路
class Solution2:
    def minDepth(self, root: TreeNode) -> int:
        # 基本情况：如果节点为空，返回深度为0
        if root is None:
            return 0

        # 递归计算左子树的最小深度
        leftDepth = self.minDepth(root.left)
        # 递归计算右子树的最小深度
        rightDepth = self.minDepth(root.right)

        # 特殊情况处理：如果左子树为空，返回右子树的深度加1
        if leftDepth == 0:
            return rightDepth + 1
        # 特殊情况处理：如果右子树为空，返回左子树的深度加1
        if rightDepth == 0:
            return leftDepth + 1

        # 计算并返回最小深度：左右子树深度的最小值加1
        return min(leftDepth, rightDepth) + 1


# BFS 的思路
from collections import deque

class Solution3:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        q = deque([root])
        # root 本身就是一层，depth 初始化为 1
        depth = 1

        while q: # <extend down -200>![](https://labuladong.online/algo/images/dijkstra/1.jpeg) #
            sz = len(q)
            # 遍历当前层的节点
            for i in range(sz):
                cur = q.popleft()
                # 判断是否到达叶子结点
                if cur.left is None and cur.right is None:
                    return depth
                # 将下一层节点加入队列
                if cur.left is not None:
                    q.append(cur.left)
                if cur.right is not None:
                    q.append(cur.right)
            # 这里增加步数
            depth += 1
        return depth
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
// 「遍历」的递归思路
class Solution {
    private int minDepth = Integer.MAX_VALUE;
    private int currentDepth = 0;

    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        traverse(root);
        return minDepth;
    }

    private void traverse(TreeNode root) {
        if (root == null) {
            return;
        }

        // 做选择：在进入节点时增加当前深度
        currentDepth++;

        // 如果当前节点是叶子节点，更新最小深度
        if (root.left == null && root.right == null) {
            minDepth = Math.min(minDepth, currentDepth);
        }

        traverse(root.left);
        traverse(root.right);

        // 撤销选择：在离开节点时减少当前深度
        currentDepth--;
    }
}

// 「分解问题」的递归思路
class Solution2 {
    public int minDepth(TreeNode root) {
        // 基本情况：如果节点为空，返回深度为0
        if (root == null) {
            return 0;
        }

        // 递归计算左子树的最小深度
        int leftDepth = minDepth(root.left);
        // 递归计算右子树的最小深度
        int rightDepth = minDepth(root.right);

        // 特殊情况处理：如果左子树为空，返回右子树的深度加1
        if (leftDepth == 0) {
            return rightDepth + 1;
        }
        // 特殊情况处理：如果右子树为空，返回左子树的深度加1
        if (rightDepth == 0) {
            return leftDepth + 1;
        }

        // 计算并返回最小深度：左右子树深度的最小值加1
        return Math.min(leftDepth, rightDepth) + 1;
    }
}


// BFS 的思路
class Solution3 {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        // root 本身就是一层，depth 初始化为 1
        int depth = 1;

        while (!q.isEmpty()) {/**<extend down -200>![](https://labuladong.online/algo/images/dijkstra/1.jpeg) */
            int sz = q.size();
            // 遍历当前层的节点
            for (int i = 0; i < sz; i++) {
                TreeNode cur = q.poll();
                // 判断是否到达叶子结点
                if (cur.left == null && cur.right == null)
                    return depth;
                // 将下一层节点加入队列
                if (cur.left != null)
                    q.offer(cur.left);
                if (cur.right != null)
                    q.offer(cur.right);
            }
            // 这里增加步数
            depth++;
        }
        return depth;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

// 「遍历」的递归思路
func minDepth(root *TreeNode) int {
    minDepth := int(^uint(0) >> 1) // Initialize to maximum integer
    var currentDepth int
    if root == nil {
        return 0
    }
    traverse(root, &currentDepth, &minDepth)
    return minDepth
}

func traverse(root *TreeNode, currentDepth, minDepth *int) {
    if root == nil {
        return
    }

    // 做选择：在进入节点时增加当前深度
    *currentDepth++

    // 如果当前节点是叶子节点，更新最小深度
    if root.Left == nil && root.Right == nil {
        if *currentDepth < *minDepth {
            *minDepth = *currentDepth
        }
    }

    traverse(root.Left, currentDepth, minDepth)
    traverse(root.Right, currentDepth, minDepth)

    // 撤销选择：在离开节点时减少当前深度
    *currentDepth--
}

// 「分解问题」的递归思路
func minDepth2(root *TreeNode) int {
    // 基本情况：如果节点为空，返回深度为0
    if root == nil {
        return 0
    }

    // 递归计算左子树的最小深度
    leftDepth := minDepth2(root.Left)
    // 递归计算右子树的最小深度
    rightDepth := minDepth2(root.Right)

    // 特殊情况处理：如果左子树为空，返回右子树的深度加1
    if leftDepth == 0 {
        return rightDepth + 1
    }
    // 特殊情况处理：如果右子树为空，返回左子树的深度加1
    if rightDepth == 0 {
        return leftDepth + 1
    }

    // 计算并返回最小深度：左右子树深度的最小值加1
    if leftDepth < rightDepth {
        return leftDepth + 1
    }
    return rightDepth + 1
}

// BFS 的思路
func minDepth3(root *TreeNode) int {
    if root == nil {
        return 0
    }
    queue := []*TreeNode{root}
    // root 本身就是一层，depth 初始化为 1
    depth := 1

    for len(queue) > 0 {
        sz := len(queue)
        // 遍历当前层的节点
        for i := 0; i < sz; i++ {
            cur := queue[0]
            queue = queue[1:]
            // 判断是否到达叶子结点
            if cur.Left == nil && cur.Right == nil {
                return depth
            }
            // 将下一层节点加入队列
            if cur.Left != nil {
                queue = append(queue, cur.Left)
            }
            if cur.Right != nil {
                queue = append(queue, cur.Right)
            }
        }
        // 这里增加步数
        depth++
    }
    return depth
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

// 「遍历」的递归思路
var minDepth = function(root) {
    let minDepth = Infinity;
    let currentDepth = 0;

    var traverse = function(root) {
        if (root === null) {
            return;
        }

        // 做选择：在进入节点时增加当前深度
        currentDepth++;

        // 如果当前节点是叶子节点，更新最小深度
        if (root.left === null && root.right === null) {
            minDepth = Math.min(minDepth, currentDepth);
        }

        traverse(root.left);
        traverse(root.right);

        // 撤销选择：在离开节点时减少当前深度
        currentDepth--;
    }

    if (root === null) {
        return 0;
    }
    traverse(root);
    return minDepth;
};

// 「分解问题」的递归思路
var minDepth2 = function(root) {
    // 基本情况：如果节点为空，返回深度为0
    if (root === null) {
        return 0;
    }

    // 递归计算左子树的最小深度
    let leftDepth = minDepth2(root.left);
    // 递归计算右子树的最小深度
    let rightDepth = minDepth2(root.right);

    // 特殊情况处理：如果左子树为空，返回右子树的深度加1
    if (leftDepth === 0) {
        return rightDepth + 1;
    }
    // 特殊情况处理：如果右子树为空，返回左子树的深度加1
    if (rightDepth === 0) {
        return leftDepth + 1;
    }

    // 计算并返回最小深度：左右子树深度的最小值加1
    return Math.min(leftDepth, rightDepth) + 1;
};

// BFS 的思路
var minDepth3 = function(root) {
    if (root === null) return 0;
    let q = [];
    q.push(root);
    // root 本身就是一层，depth 初始化为 1
    let depth = 1;

    while (q.length > 0) {
        let sz = q.length;
        // 遍历当前层的节点
        for (let i = 0; i < sz; i++) {
            let cur = q.shift();
            // 判断是否到达叶子结点
            if (cur.left === null && cur.right === null)
                return depth;
            // 将下一层节点加入队列
            if (cur.left !== null)
                q.push(cur.left);
            if (cur.right !== null)
                q.push(cur.right);
        }
        // 这里增加步数
        depth++;
    }
    return depth;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🍭🍭 算法可视化 🍭🍭</strong></summary><div id="data_minimum-depth-of-binary-tree"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_minimum-depth-of-binary-tree"></div></div>
</details><hr /><br />

</div>
</details>
</div>



