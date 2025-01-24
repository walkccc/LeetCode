class Solution:
  def maxLevelSum(self, root: TreeNode | None) -> int:
    ans = 0
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
      if levelSum > maxLevelSum:
        maxLevelSum = levelSum
        ans = level
      level += 1

    return ans
