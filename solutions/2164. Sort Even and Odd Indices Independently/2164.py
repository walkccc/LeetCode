class Solution:
  def sortEvenOdd(self, nums: list[int]) -> list[int]:
    ans = [0] * len(nums)
    evenCount = collections.Counter(nums[::2])
    oddCount = collections.Counter(nums[1::2])

    ansIndex = 0
    for i in range(1, 101):
      while evenCount[i] > 0:
        ans[ansIndex] = i
        ansIndex += 2
        evenCount[i] -= 1

    ansIndex = 1
    for i in range(100, 0, -1):
      while oddCount[i] > 0:
        ans[ansIndex] = i
        ansIndex += 2
        oddCount[i] -= 1

    return ans
