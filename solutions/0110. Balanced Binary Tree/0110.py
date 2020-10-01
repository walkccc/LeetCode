class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def maxDepth(root: TreeNode) -> int:
            if not root:
                return 0
            return 1 + max(maxDepth(root.left), maxDepth(root.right))

        if not root:
            return True
        return abs(maxDepth(root.left) - maxDepth(root.right)) <= 1 and \
            self.isBalanced(root.left) and self.isBalanced(root.right)
