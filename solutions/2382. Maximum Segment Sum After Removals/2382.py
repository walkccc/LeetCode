class Solution:
  def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
    n = len(nums)
    maxSum = 0
    ans = [0] * n
    # for segment [l, r], record its sum in summ[l] and summ[r]
    summ = [0] * n
    # for segment [l, r], record its count in count[l] and count[r]
    count = [0] * n

    for i in reversed(range(n)):
      ans[i] = maxSum
      j = removeQueries[i]

      # calculate `segmentSum`
      leftSum = summ[j - 1] if j > 0 else 0
      rightSum = summ[j + 1] if j + 1 < n else 0
      segmentSum = nums[j] + leftSum + rightSum

      # calculate `segmentCount`
      leftCount = count[j - 1] if j > 0 else 0
      rightCount = count[j + 1] if j + 1 < n else 0
      segmentCount = 1 + leftCount + rightCount

      # update `summ` and `count`` of segment [l, r]
      l = j - leftCount
      r = j + rightCount
      summ[l] = segmentSum
      summ[r] = segmentSum
      count[l] = segmentCount
      count[r] = segmentCount
      maxSum = max(maxSum, segmentSum)

    return ans
