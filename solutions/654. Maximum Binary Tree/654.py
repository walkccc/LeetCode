class Solution:
  def constructMaximumBinaryTree(self, nums: list[int]) -> TreeNode | None:
    def build(i: int, j: int) -> TreeNode | None:
      if i > j:
        return None

      maxNum = max(nums[i:j + 1])
      maxIndex = nums.index(maxNum)

      root = TreeNode(maxNum)
      root.left = build(i, maxIndex - 1)
      root.right = build(maxIndex + 1, j)
      return root

    return build(0, len(nums) - 1)
