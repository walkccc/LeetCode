class Solution:
  def maxDepth(self, root: 'Node') -> int:
    if not root:
      return 0
    if not root.children:
      return 1
    return 1 + max(self.maxDepth(child) for child in root.children)
