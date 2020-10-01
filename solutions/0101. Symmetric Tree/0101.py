class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def helper(p: TreeNode, q: TreeNode) -> bool:
            if not p or not q:
                return p == q

            return p.val == q.val and \
                helper(p.left, q.right) and \
                helper(p.right, q.left)

        return helper(root, root)
