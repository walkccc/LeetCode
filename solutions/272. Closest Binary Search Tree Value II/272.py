class Solution:
  def closestKValues(
      self,
      root: TreeNode | None,
      target: float,
      k: int,
  ) -> list[int]:
    dq = collections.deque()

    def inorder(root: TreeNode | None) -> None:
      if not root:
        return

      inorder(root.left)
      dq.append(root.val)
      inorder(root.right)

    inorder(root)

    while len(dq) > k:
      if abs(dq[0] - target) > abs(dq[-1] - target):
        dq.popleft()
      else:
        dq.pop()

    return list(dq)
