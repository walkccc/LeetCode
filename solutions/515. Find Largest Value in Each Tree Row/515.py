class Solution:
  def largestValues(self, root: TreeNode | None) -> list[int]:
    if not root:
      return []

    ans = []
    q = collections.deque([root])

    while q:
      mx = -math.inf
      for _ in range(len(q)):
        root = q.popleft()
        mx = max(mx, root.val)
        if root.left:
          q.append(root.left)
        if root.right:
          q.append(root.right)
      ans.append(mx)

    return ans
