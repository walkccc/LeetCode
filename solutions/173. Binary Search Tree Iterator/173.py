class BSTIterator:
  def __init__(self, root: Optional[TreeNode]):
    self.i = 0
    self.vals = []
    self._inorder(root)

  def next(self) -> int:
    self.i += 1
    return self.vals[self.i - 1]

  def hasNext(self) -> bool:
    return self.i < len(self.vals)

  def _inorder(self, root: Optional[TreeNode]) -> None:
    if not root:
      return
    self._inorder(root.left)
    self.vals.append(root.val)
    self._inorder(root.right)
