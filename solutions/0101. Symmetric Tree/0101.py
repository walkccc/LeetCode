class Solution:
  def isSymmetric(self, root: TreeNode) -> bool:
    def isSymmetric(p: TreeNode, q: TreeNode) -> bool:
      if not p or not q:
        return p == q

      return p.val == q.val and \
          isSymmetric(p.left, q.right) and \
          isSymmetric(p.right, q.left)

    return isSymmetric(root, root)
