class Solution:
  def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
    q = collections.deque([root])
    isEven = True

    while q:
      prevVal = -math.inf if isEven else math.inf
      for _ in range(sz):
        node = q.popleft()
        if isEven and (node.val % 2 == 0 or node.val <= prevVal):
          return False  # invalid case on even level
        if not isEven and (node.val % 2 == 1 or node.val >= prevVal):
          return False  # invalid case on odd level
        prevVal = node.val
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      isEven = not isEven

    return True
