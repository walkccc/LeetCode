class Solution:
  def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
    ans = []
    xToNodes = collections.defaultdict(list)

    def dfs(node: Optional[TreeNode], x: int, y: int) -> None:
      if not node:
        return

      xToNodes[x].append((-y, node.val))
      dfs(node.left, x - 1, y - 1)
      dfs(node.right, x + 1, y - 1)

    dfs(root, 0, 0)

    for _, nodes in sorted(xToNodes.items(), key=lambda item: item[0]):
      ans.append([val for _, val in sorted(nodes)])

    return ans
