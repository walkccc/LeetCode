class Solution:
  def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
    def helper(l: int, r: int) -> TreeNode:
      if l > r:
        return None

      m = (l + r) // 2
      root = TreeNode(nums[m])
      root.left = helper(l, m - 1)
      root.right = helper(m + 1, r)

      return root

    return helper(0, len(nums) - 1)
