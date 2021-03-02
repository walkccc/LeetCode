class Solution:
  def rob(self, root: TreeNode) -> int:
    def robOrNot(root: TreeNode) -> tuple:
      if not root:
        return (0, 0)

      robLeft, notRobLeft = robOrNot(root.left)
      robRight, notRobRight = robOrNot(root.right)

      return (root.val + notRobLeft + notRobRight,
              max(robLeft, notRobLeft) + max(robRight, notRobRight))

    return max(robOrNot(root))
