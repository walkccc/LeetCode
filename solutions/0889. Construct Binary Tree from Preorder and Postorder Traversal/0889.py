class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        return self.helper(0, 0, len(pre), pre, post)

    def helper(self, i: int, j: int, n: int, pre: List[int], post: List[int]) -> TreeNode:
        if n == 0:
            return None

        root = TreeNode(pre[i])
        if n == 1:
            return root

        k = j
        while post[k] != pre[i + 1]:
            k += 1
        l = k - j + 1

        root.left = self.helper(i + 1, j, l, pre, post)
        root.right = self.helper(i + l + 1, j + l, n - l - 1, pre, post)

        return root
