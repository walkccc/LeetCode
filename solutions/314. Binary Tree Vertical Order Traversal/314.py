class Solution:
  def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
      return []

    range_ = [0] * 2

    def getRange(root: Optional[TreeNode], x: int) -> None:
      if not root:
        return

      range_[0] = min(range_[0], x)
      range_[1] = max(range_[1], x)

      getRange(root.left, x - 1)
      getRange(root.right, x + 1)

    getRange(root, 0)  # Get the leftmost and the rightmost x index.

    ans = [[] for _ in range(range_[1] - range_[0] + 1)]
    q = collections.deque([(root, -range_[0])])  # (TreeNode, x)

    while q:
      node, x = q.popleft()
      ans[x].append(node.val)
      if node.left:
        q.append((node.left, x - 1))
      if node.right:
        q.append((node.right, x + 1))

    return ans
