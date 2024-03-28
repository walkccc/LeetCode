class Solution:
  def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
    def build(i: int, j: int) -> Optional[TreeNode]:
      if i > j:
        return None

      maxNum = max(nums[i:j + 1])
      maxIndex = nums.index(maxNum)

      root = TreeNode(maxNum)
      root.left = build(i, maxIndex - 1)
      root.right = build(maxIndex + 1, j)
      return root

    return build(0, len(nums) - 1)
