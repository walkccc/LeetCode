class Solution:
  def matrixReshape(self, nums: list[list[int]],
                    r: int, c: int) -> list[list[int]]:
    if nums == [] or r * c != len(nums) * len(nums[0]):
      return nums

    ans = [[0 for j in range(c)] for i in range(r)]
    k = 0

    for row in nums:
      for num in row:
        ans[k // c][k % c] = num
        k += 1

    return ans
