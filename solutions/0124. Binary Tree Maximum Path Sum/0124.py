class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def maxPathSumDownFrom(root: TreeNode) -> int:
            if not root:
                return 0

            left = max(maxPathSumDownFrom(root.left), 0)
            right = max(maxPathSumDownFrom(root.right), 0)
            self.ans = max(self.ans, root.val + left + right)

            return root.val + max(left, right)

        self.ans = float('-inf')

        maxPathSumDownFrom(root)

        return self.ans
