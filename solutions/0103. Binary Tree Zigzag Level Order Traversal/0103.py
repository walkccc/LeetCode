class Solution:
  def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
    if not root:
      return []

    ans = []
    deque = deque([root])
    isLeftToRight = True

    while deque:
      currLevel = []
      for i in range(len(deque)):
        if isLeftToRight:
          node = deque.popleft()
          currLevel.append(node.val)
          if node.left:
            deque.append(node.left)
          if node.right:
            deque.append(node.right)
        else:
          node = deque.pop()
          currLevel.append(node.val)
          if node.right:
            deque.appendleft(node.right)
          if node.left:
            deque.appendleft(node.left)
      ans.append(currLevel)
      isLeftToRight = not isLeftToRight

    return ans
