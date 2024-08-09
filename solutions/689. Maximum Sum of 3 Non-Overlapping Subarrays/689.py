class Solution:
  def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
    n = len(nums) - k + 1
    # sums[i] := sum(nums[i..i + k))
    sums = [0] * n
    # l[i] := the index in [0..i] that has the maximum sums[i]
    l = [0] * n
    # r[i] := the index in [i..n) that has the maximum sums[i]
    r = [0] * n

    summ = 0
    for i, num in enumerate(nums):
      summ += num
      if i >= k:
        summ -= nums[i - k]
      if i >= k - 1:
        sums[i - k + 1] = summ

    maxIndex = 0
    for i in range(n):
      if sums[i] > sums[maxIndex]:
        maxIndex = i
      l[i] = maxIndex

    maxIndex = n - 1
    for i in range(n - 1, -1, -1):
      if sums[i] >= sums[maxIndex]:
        maxIndex = i
      r[i] = maxIndex

    ans = [-1, -1, -1]

    for i in range(k, n - k):
      if ans[0] == -1 or sums[ans[0]] + sums[ans[1]] + sums[ans[2]] <\
              sums[l[i - k]] + sums[i] + sums[r[i + k]]:
        ans[0] = l[i - k]
        ans[1] = i
        ans[2] = r[i + k]

    return ans
