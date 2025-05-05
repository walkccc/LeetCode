class Solution:
  def recoverTree(self, root: TreeNode | None) -> None:
    def swap(x: TreeNode | None, y: TreeNode | None) -> None:
      temp = x.val
      x.val = y.val
      y.val = temp

    def inorder(root: TreeNode | None) -> None:
      if not root:
        return

      inorder(root.left)

      if self.pred and root.val < self.pred.val:
        self.y = root
        if not self.x:
          self.x = self.pred
        else:
          return
      self.pred = root

      inorder(root.right)

    inorder(root)
    swap(self.x, self.y)

  pred = None
  x = None  # the first wrong node
  y = None  # the second wrong node
