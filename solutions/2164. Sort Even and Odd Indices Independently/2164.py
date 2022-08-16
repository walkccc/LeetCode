class Solution:
  def sortEvenOdd(self, nums: List[int]) -> List[int]:
    ans = [0] * len(nums)
    evenCount = Counter(nums[::2])
    oddCount = Counter(nums[1::2])

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
