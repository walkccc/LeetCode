class Solution:
  def splitBST(self, root: Optional[TreeNode], target: int) -> List[Optional[TreeNode]]:
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
