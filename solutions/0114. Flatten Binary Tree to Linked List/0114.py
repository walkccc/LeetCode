class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    if not root:
      return

    self.flatten(root.left)
    self.flatten(root.right)

    left = root.left  # Flattened left
    right = root.right  # Flattened right

    root.left = None
    root.right = left

    # Connect the original right subtree
    # To the end of new right subtree
    rightmost = root
    while rightmost.right:
      rightmost = rightmost.right
    rightmost.right = right
