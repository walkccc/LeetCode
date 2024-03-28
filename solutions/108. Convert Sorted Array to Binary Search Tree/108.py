class Solution:
  def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
    def build(l: int, r: int) -> Optional[TreeNode]:
      if l > r:
        return None
      m = (l + r) // 2
      return TreeNode(nums[m],
                      build(l, m - 1),
                      build(m + 1, r))

    return build(0, len(nums) - 1)
