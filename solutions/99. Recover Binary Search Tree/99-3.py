class Solution:
  def recoverTree(self, root: TreeNode | None) -> None:
    pred = None
    x = None  # the first wrong node
    y = None  # the second wrong node

    def findPredecessor(root: TreeNode | None) -> TreeNode | None:
      pred = root.left
      while pred.right and pred.right != root:
        pred = pred.right
      return pred

    while root:
      if root.left:
        morrisPred = findPredecessor(root)
        if morrisPred.right:
          # The node has already been connected before.
          # Start the main logic.
          if pred and root.val < pred.val:
            y = root
            if not x:
              x = pred
          pred = root
          # End of the main logic
          morrisPred.right = None  # Break the connection.
          root = root.right
        else:
          morrisPred.right = root  # Connect it.
          root = root.left
      else:
        # Start the main logic.
        if pred and root.val < pred.val:
          y = root
          if not x:
            x = pred
        pred = root
        # End of the main logic.
        root = root.right

    def swap(x: TreeNode | None, y: TreeNode | None) -> None:
      temp = x.val
      x.val = y.val
      y.val = temp

    swap(x, y)
