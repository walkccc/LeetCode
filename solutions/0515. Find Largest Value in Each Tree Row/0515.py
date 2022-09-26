class Solution:
  def largestValues(self, root: Optional[TreeNode]) -> List[int]:
    if not root:
      return []

    ans = []
    q = deque([root])

    while q:
      maxi = -math.inf
      for _ in range(len(q)):
        root = q.popleft()
        maxi = max(maxi, root.val)
        if root.left:
          q.append(root.left)
        if root.right:
          q.append(root.right)
      ans.append(maxi)

    return ans
