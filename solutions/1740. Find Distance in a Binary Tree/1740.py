class Solution:
  def findDistance(self, root: TreeNode, p: int, q: int) -> int:
    def getLCA(root, p, q):
      if not root or root.val == p or root.val == q:
        return root

      l = getLCA(root.left, p, q)
      r = getLCA(root.right, p, q)

      if l and r:
        return root
      return l or r

    def dist(lca, target):
      if not lca:
        return 10000
      if lca.val == target:
        return 0
      return 1 + min(dist(lca.left, target), dist(lca.right, target))

    lca = getLCA(root, p, q)
    return dist(lca, p) + dist(lca, q)
