class Solution:
  def levelOrder(self, root: 'Node') -> list[list[int]]:
    if not root:
      return []

    ans = []
    q = collections.deque([root])

    while q:
      currLevel = []
      for _ in range(len(q)):
        node = q.popleft()
        currLevel.append(node.val)
        for child in node.children:
          q.append(child)
      ans.append(currLevel)

    return ans
