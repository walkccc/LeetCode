class Solution:
  def closestKValues(self, root: Optional[TreeNode], target: float, k: int) -> List[int]:
    q = deque()

    def inorder(root: Optional[TreeNode]) -> None:
      if not root:
        return

      inorder(root.left)
      q.append(root.val)
      inorder(root.right)

    inorder(root)

    while len(q) > k:
      if abs(q[0] - target) > abs(q[-1] - target):
        q.popleft()
      else:
        q.pop()

    return list(q)
