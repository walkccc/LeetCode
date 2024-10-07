class Solution:
  def splitBST(self, root: TreeNode | None, target: int) -> list[TreeNode | None]:
    if not root:
      return None, None
    if root.val > target:
      left, right = self.splitBST(root.left, target)
      root.left = right
      return left, root
    else:  # root.val <= target
      left, right = self.splitBST(root.right, target)
      root.right = left
      return root, right
