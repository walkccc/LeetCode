class BSTIterator:
  def __init__(self, root: TreeNode | None):
    self.prevsAndCurr = []
    self.nexts = []
    self._pushLeftsUntilNull(root)

  def hasNext(self) -> bool:
    return len(self.nexts) > 0

  def next(self) -> int:
    root, fromNext = self.nexts.pop()
    if fromNext:
      self._pushLeftsUntilNull(root.right)
    self.prevsAndCurr.append(root)
    return root.val

  def hasPrev(self) -> bool:
    return len(self.prevsAndCurr) > 1

  def prev(self) -> int:
    self.nexts.append((self.prevsAndCurr.pop(), False))
    return self.prevsAndCurr[-1].val

  def _pushLeftsUntilNull(self, root):
    while root:
      self.nexts.append((root, True))
      root = root.left
