class Solution:
  def countNodes(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0
    return 1 + self.countNodes(root.left) + self.countNodes(root.right)
