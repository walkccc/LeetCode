class Solution:
  def getKthCharacter(self, root: Optional[object], k: int) -> str:
    """:type root: Optional[RopeTreeNode]"""
    while root.len > 0:
      leftLen = 0 if root.left is None \
          else max(root.left.len, len(root.left.val))
      if leftLen >= k:
        root = root.left
      else:
        root = root.right
        k -= leftLen
    return root.val[k - 1]
