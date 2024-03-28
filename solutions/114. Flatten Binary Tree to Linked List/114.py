class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    if not root:
      return

    self.flatten(root.left)
    self.flatten(root.right)

    left = root.left  # flattened left
    right = root.right  # flattened right

    root.left = None
    root.right = left

    # Connect the original right subtree to the end of the new right subtree.
    rightmost = root
    while rightmost.right:
      rightmost = rightmost.right
    rightmost.right = right
