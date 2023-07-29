class Solution:
  def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if not p or not q:
      return p == q
    return p.val == q.val and \
        self.isSameTree(p.left, q.left) and \
        self.isSameTree(p.right, q.right)
