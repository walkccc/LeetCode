class Solution:
  def isSymmetric(self, root: Optional[TreeNode]) -> bool:
    def isSymmetric(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
      if not p or not q:
        return p == q

      return p.val == q.val and \
          isSymmetric(p.left, q.right) and \
          isSymmetric(p.right, q.left)

    return isSymmetric(root, root)
