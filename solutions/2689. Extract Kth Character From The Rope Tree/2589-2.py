class Solution:
  def getKthCharacter(self, root: object | None, k: int) -> str:
    """:type root: RopeTreeNode | None"""
    while root.len > 0:
      leftLen = (0 if not root.left
                 else max(root.left.len, len(root.left.val)))
      if leftLen >= k:
        root = root.left
      else:
        root = root.right
        k -= leftLen
    return root.val[k - 1]
