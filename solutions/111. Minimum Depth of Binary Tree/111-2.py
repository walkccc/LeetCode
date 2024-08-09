class Solution:
  def minDepth(self, root: Optional[TreeNode]) -> int:
    if not root:
      return 0

    ans = 0
    q = collections.deque([root])

    while q:
      ans += 1
      for _ in range(len(q)):
        node = q.popleft()
        if not node.left and not node.right:
          return ans
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
