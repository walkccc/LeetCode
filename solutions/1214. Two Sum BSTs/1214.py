class BSTIterator:
  def __init__(self, root: Optional[TreeNode], leftToRight: bool):
    self.stack = []
    self.leftToRight = leftToRight
    self._pushUntilNone(root)

  def hasNext(self) -> bool:
    return len(self.stack) > 0

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
  def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
    bst1 = BSTIterator(root1, True)
    bst2 = BSTIterator(root2, False)

    l = bst1.next()
    r = bst2.next()
    while True:
      summ = l + r
      if summ == target:
        return True
      if summ < target:
        if not bst1.hasNext():
          return False
        l = bst1.next()
      else:
        if not bst2.hasNext():
          return False
        r = bst2.next()
