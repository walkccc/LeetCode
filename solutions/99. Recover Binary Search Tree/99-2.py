class Solution:
  def recoverTree(self, root: TreeNode | None) -> None:
    pred = None
    x = None  # the first wrong node
    y = None  # the second wrong node
    stack = []

    while root or stack:
      while root:
        stack.append(root)
        root = root.left
      root = stack.pop()
      if pred and root.val < pred.val:
        y = root
        if not x:
          x = pred
      pred = root
      root = root.right

    def swap(x: TreeNode | None, y: TreeNode | None) -> None:
      temp = x.val
      x.val = y.val
      y.val = temp

    swap(x, y)
