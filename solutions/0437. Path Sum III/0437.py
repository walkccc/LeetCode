class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0

        return self.helper(root, sum) + \
            self.pathSum(root.left, sum) + \
            self.pathSum(root.right, sum)

    def helper(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0

        return (sum == root.val) + \
            self.helper(root.left, sum - root.val) + \
            self.helper(root.right, sum - root.val)
