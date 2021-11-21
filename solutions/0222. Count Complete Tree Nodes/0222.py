class Solution:
  def countNodes(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0

    ans = 0

    queue = deque([root])

    while queue:
      ans += 1
      node = queue.popleft()
      if node.left:
        queue.append(node.left)
      if node.right:
        queue.append(node.right)

    return ans
