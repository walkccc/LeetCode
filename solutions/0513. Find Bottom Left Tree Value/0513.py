class Solution:
  def findBottomLeftValue(self, root: TreeNode) -> int:
    queue = deque([root])

    while queue:
      root = queue.popleft()
      if root.right:
        queue.append(root.right)
      if root.left:
        queue.append(root.left)

    return root.val
