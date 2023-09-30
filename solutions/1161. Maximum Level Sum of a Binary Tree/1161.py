class Solution:
  def maxLevelSum(self, root: Optional[TreeNode]) -> int:
    ans = 1
    maxLevelSum = -math.inf
    q = collections.deque([root])

    level = 1
    while q:
      levelSum = 0
      for _ in range(len(q)):
        node = q.popleft()
        levelSum += node.val
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      if maxLevelSum < levelSum:
        maxLevelSum = levelSum
        ans = level
      level += 1

    return ans
