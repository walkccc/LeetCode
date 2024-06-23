class Solution:
  def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
    sortedVals = []
    self._inorder(root, sortedVals)

    def getClosestPair(query: int) -> List[int]:
      i = bisect_left(sortedVals, query)
      # query is presented in the tree, so just use [query, query].
      if i != len(sortedVals) and sortedVals[i] == query:
        return [query, query]
      # query isn't presented in the tree, so find the cloest one if possible.
      return [-1 if i == 0 else sortedVals[i - 1],
              -1 if i == len(sortedVals) else sortedVals[i]]

    return [getClosestPair(query) for query in queries]

  def _inorder(self, root: Optional[TreeNode], sortedVals: List[int]) -> None:
    """Walks the BST to collect the sorted numbers."""
    if not root:
      return
    self._inorder(root.left, sortedVals)
    sortedVals.append(root.val)
    self._inorder(root.right, sortedVals)
