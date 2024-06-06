class Solution:
  def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
    nodes = set(nodes)

    def lca(root: 'TreeNode') -> 'TreeNode':
      if not root:
        return None
      if root in nodes:
        return root
      left = lca(root.left)
      right = lca(root.right)
      if left and right:
        return root
      return left or right

    return lca(root)
