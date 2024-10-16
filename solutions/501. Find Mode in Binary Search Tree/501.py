class Solution:
  def findMode(self, root: TreeNode | None) -> list[int]:
    self.ans = []
    self.pred = None
    self.count = 0
    self.maxCount = 0

    def updateCount(root: TreeNode | None) -> None:
      if self.pred and self.pred.val == root.val:
        self.count += 1
      else:
        self.count = 1

      if self.count > self.maxCount:
        self.maxCount = self.count
        self.ans = [root.val]
      elif self.count == self.maxCount:
        self.ans.append(root.val)

      self.pred = root

    def inorder(root: TreeNode | None) -> None:
      if not root:
        return

      inorder(root.left)
      updateCount(root)
      inorder(root.right)

    inorder(root)
    return self.ans
