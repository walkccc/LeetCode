class Solution:
  def findUnsortedSubarray(self, nums: List[int]) -> int:
    mini = inf
    maxi = -inf
    flag = False

    for i in range(1, len(nums)):
      if nums[i] < nums[i - 1]:
        flag = True
      if flag:
        mini = min(mini, nums[i])

    flag = False

    for i in range(len(nums) - 2, -1, -1):
      if nums[i] > nums[i + 1]:
        flag = True
      if flag:
        maxi = max(maxi, nums[i])

    for l in range(len(nums)):
      if nums[l] > mini:
        break

    for r in range(len(nums) - 1, -1, -1):
      if nums[r] < maxi:
        break

    return 0 if l >= r else r - l + 1
