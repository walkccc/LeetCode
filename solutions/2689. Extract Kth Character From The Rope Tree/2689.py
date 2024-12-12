class Solution:
  def getKthCharacter(self, root: object | None, k: int) -> str:
    """:type root: RopeTreeNode | None"""
    if root.len == 0:
      return root.val[k - 1]
    leftLen = (0 if not root.left
               else max(root.left.len, len(root.left.val)))
    if leftLen >= k:
      return self.getKthCharacter(root.left, k)
    return self.getKthCharacter(root.right, k - leftLen)
