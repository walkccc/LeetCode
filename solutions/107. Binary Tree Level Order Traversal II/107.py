class Solution:
  def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
      return []

    ans = []
    q = collections.deque([root])

    while q:
      currLevel = []
      for _ in range(len(q)):
        node = q.popleft()
        currLevel.append(node.val)
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      ans.append(currLevel)

    return ans[::-1]
