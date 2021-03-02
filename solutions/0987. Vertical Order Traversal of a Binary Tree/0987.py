class Solution:
  def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
    def dfs(node: TreeNode, x: int, y: int) -> None:
      if not node:
        return

      xToNodes[x].append((-y, node.val))
      dfs(node.left, x - 1, y - 1)
      dfs(node.right, x + 1, y - 1)

    ans = []
    xToNodes = defaultdict(list)

    dfs(root, 0, 0)

    for _, nodes in sorted(xToNodes.items(), key=lambda item: item[0]):
      ans.append([val for _, val in sorted(nodes)])

    return ans
