class Solution:
  def isSymmetric(self, root: TreeNode | None) -> bool:
    def isSymmetric(p: TreeNode | None, q: TreeNode | None) -> bool:
      if not p or not q:
        return p == q
      return (p.val == q.val and
              isSymmetric(p.left, q.right) and
              isSymmetric(p.right, q.left))

    return isSymmetric(root, root)
