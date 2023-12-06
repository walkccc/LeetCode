class Solution:
  def getKthCharacter(self, root: Optional[object], k: int) -> str:
    """:type root: Optional[RopeTreeNode]"""
    if root.len == 0:
      return root.val[k - 1]
    leftLen = 0 if root.left is None \
        else max(root.left.len, len(root.left.val))
    if leftLen >= k:
      return self.getKthCharacter(root.left, k)
    return self.getKthCharacter(root.right, k - leftLen)
