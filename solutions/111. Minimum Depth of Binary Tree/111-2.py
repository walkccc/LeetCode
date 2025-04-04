class Solution:
  def minDepth(self, root: TreeNode | None) -> int:
    if not root:
      return 0

    q = collections.deque([root])

    step = 1
    while q:
      for _ in range(len(q)):
        node = q.popleft()
        if not node.left and not node.right:
          return step
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      step += 1
