class Solution:
  def diameter(self, root: 'Node') -> int:
    ans = 0

    def maxDepth(root: 'Node') -> int:
      """Returns the maximum depth of the subtree rooted at `root`."""
      nonlocal ans
      maxSubDepth1 = 0
      maxSubDepth2 = 0
      for child in root.children:
        maxSubDepth = maxDepth(child)
        if maxSubDepth > maxSubDepth1:
          maxSubDepth2 = maxSubDepth1
          maxSubDepth1 = maxSubDepth
        elif maxSubDepth > maxSubDepth2:
          maxSubDepth2 = maxSubDepth
      ans = max(ans, maxSubDepth1 + maxSubDepth2)
      return 1 + maxSubDepth1

    maxDepth(root)
    return ans
