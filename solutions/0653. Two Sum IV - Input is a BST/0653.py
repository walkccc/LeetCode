class BSTIterator:
  def __init__(self, root: Optional[TreeNode], leftToRight: bool):
    self.stack = []
    self.leftToRight = leftToRight
    self._pushUntilNone(root)

  def next(self) -> int:
    node = self.stack.pop()
    if self.leftToRight:
      self._pushUntilNone(node.right)
    else:
      self._pushUntilNone(node.left)
    return node.val

  def _pushUntilNone(self, root: Optional[TreeNode]):
    while root:
      self.stack.append(root)
      root = root.left if self.leftToRight else root.right


class Solution:
  def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
    if not root:
      return False

    left = BSTIterator(root, True)
    right = BSTIterator(root, False)

    l = left.next()
    r = right.next()
    while l < r:
      summ = l + r
      if summ == k:
        return True
      if summ < k:
        l = left.next()
      else:
        r = right.next()

    return False
