class Solution:
  def pathSum(self, root: TreeNode, sum: int) -> int:
    if not root:
      return 0

    def dfs(root: TreeNode, sum: int) -> int:
      if not root:
        return 0

      return (sum == root.val) + \
          dfs(root.left, sum - root.val) + \
          dfs(root.right, sum - root.val)

    return dfs(root, sum) + \
        self.pathSum(root.left, sum) + \
        self.pathSum(root.right, sum)
