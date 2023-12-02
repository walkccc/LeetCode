class Solution:
  def findMatrix(self, nums: List[int]) -> List[List[int]]:
    # The number of rows we need equals the maximum frequency.
    ans = []
    count = [0] * (len(nums) + 1)

    for num in nums:
      count[num] += 1
      # Construct the `ans` on demand.
      if count[num] > len(ans):
        ans.append([])
      ans[count[num] - 1].append(num)

    return ans
