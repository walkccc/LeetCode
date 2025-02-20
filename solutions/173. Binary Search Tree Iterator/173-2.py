class BSTIterator:
  def __init__(self, root: TreeNode | None):
    self.stack = []
    self._pushLeftsUntilNull(root)

  def next(self) -> int:
    root = self.stack.pop()
    self._pushLeftsUntilNull(root.right)
    return root.val

  def hasNext(self) -> bool:
    return self.stack

  def _pushLeftsUntilNull(self, root: TreeNode | None) -> None:
    while root:
      self.stack.append(root)
      root = root.left
