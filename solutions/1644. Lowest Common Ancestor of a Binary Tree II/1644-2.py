class Solution:
  def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    def getLCA(root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
      if not root or root == p or root == q:
        return root
      left = getLCA(root.left, p, q)
      right = getLCA(root.right, p, q)
      if left and right:
        return root
      return left or right

    ans = getLCA(root, p, q)
    if ans == p:  # Search q in the subtree rooted at p.
      return ans if getLCA(p, q, q) else None
    if ans == q:  # Search p in the subtree rooted at q.
      return ans if getLCA(q, p, p) else None
    return ans  # (ans != p and ans != q) or ans is None
