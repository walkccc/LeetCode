class BSTIterator:
  def __init__(self, root: TreeNode):
    self.stack = []
    self.pushLeftsUntilNone(root)

  def next(self) -> int:
    root = self.stack.pop()
    self.pushLeftsUntilNone(root.right)
    return root.val

  def hasNext(self) -> bool:
    return self.stack

  def pushLeftsUntilNone(self, root: TreeNode):
    while root:
      self.stack.append(root)
      root = root.left
