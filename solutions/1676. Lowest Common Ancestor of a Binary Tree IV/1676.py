class Solution:
  def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
    nodes = set(nodes)

    def lca(root: 'TreeNode') -> 'TreeNode':
      if not root:
        return None
      if root in nodes:
        return root

      l = lca(root.left)
      r = lca(root.right)

      if l and r:
        return root
      return l or r

    return lca(root)
