class Solution:
  def upsideDownBinaryTree(self, root: TreeNode | None) -> TreeNode | None:
    prevRoot = None
    prevRightChild = None

    while root:
      nextRoot = root.left  # Cache the next root.
      root.left = prevRightChild
      prevRightChild = root.right
      root.right = prevRoot
      prevRoot = root  # Record the previous root.
      root = nextRoot  # Update the root.

    return prevRoot
