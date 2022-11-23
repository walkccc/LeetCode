class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    stack = []

    while root:
      stack.append(root)
      root = root.left

    for _ in range(k - 1):
      root = stack.pop()
      root = root.right
      while root:
        stack.append(root)
        root = root.left

    return stack[-1].val
