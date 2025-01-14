class Solution:
  def checkTree(self, root: TreeNode | None) -> bool:
    return root.val == root.left.val + root.right.val
