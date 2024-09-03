class Solution:
  def lowestCommonAncestor(
      self,
      root: 'TreeNode',
      p: 'TreeNode',
      q: 'TreeNode',
  ) -> 'TreeNode':
    seenP = False
    seenQ = False

    def getLCA(root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
      nonlocal seenP
      nonlocal seenQ
      if not root:
        return None
      # Need to traverse the entire tree to update `seenP` and `seenQ`.
      left = getLCA(root.left, p, q)
      right = getLCA(root.right, p, q)
      if root == p:
        seenP = True
        return root
      if root == q:
        seenQ = True
        return root
      if left and right:
        return root
      return left or right

    lca = getLCA(root, p, q)
    return lca if seenP and seenQ else None
