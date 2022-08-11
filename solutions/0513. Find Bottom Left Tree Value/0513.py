class Solution:
  def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
    q = deque([root])

    while q:
      root = q.popleft()
      if root.right:
        q.append(root.right)
      if root.left:
        q.append(root.left)

    return root.val
