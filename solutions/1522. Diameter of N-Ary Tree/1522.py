class Solution:
  def diameter(self, root: 'Node') -> int:
    ans = 0

    def maxDepth(root: 'Node') -> int:
      nonlocal ans
      max1 = 0
      max2 = 0

      for child in root.children:
        depth = maxDepth(child)
        if depth > max1:
          max2 = max1
          max1 = depth
        elif depth > max2:
          max2 = depth

      ans = max(ans, max1 + max2)
      return 1 + max1

    maxDepth(root)
    return ans
