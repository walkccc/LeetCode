class Solution:
  def flipEquiv(self, root1: TreeNode | None, root2: TreeNode | None) -> bool:
    if not root1:
      return not root2
    if not root2:
      return not root1
    if root1.val != root2.val:
      return False
    return (self.flipEquiv(root1.left, root2.left) and
            self.flipEquiv(root1.right, root2.right) or
            self.flipEquiv(root1.left, root2.right) and
            self.flipEquiv(root1.right, root2.left))
