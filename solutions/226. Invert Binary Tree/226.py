class Solution:
  def invertTree(self, root: TreeNode | None) -> TreeNode | None:
    if not root:
      return None

    left = root.left
    right = root.right
    root.left = self.invertTree(right)
    root.right = self.invertTree(left)
    return root
