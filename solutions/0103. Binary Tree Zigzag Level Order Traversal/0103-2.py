class Solution:
  def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
      return []

    ans = []
    q = deque([root])
    isLeftToRight = True

    while q:
      size = len(q)
      currLevel = [0] * size
      for i in range(size):
        node = q.popleft()
        index = i if isLeftToRight else size - i - 1
        currLevel[index] = node.val
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      ans.append(currLevel)
      isLeftToRight = not isLeftToRight

    return ans
