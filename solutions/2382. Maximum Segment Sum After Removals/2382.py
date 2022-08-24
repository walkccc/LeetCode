class Solution:
  def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
    n = len(nums)
    maxSum = 0
    ans = [0] * n
    # for segment [l, r], record its sum in sum[l] and sum[r]
    sum = [0] * n
    # for segment [l, r], record its count in count[l] and count[r]
    count = [0] * n

    for i in reversed(range(n)):
      ans[i] = maxSum
      j = removeQueries[i]

      # calculate `segmentSum`
      leftSum = sum[j - 1] if j > 0 else 0
      rightSum = sum[j + 1] if j + 1 < n else 0
      segmentSum = nums[j] + leftSum + rightSum

      # calculate `segmentCount`
      leftCount = count[j - 1] if j > 0 else 0
      rightCount = count[j + 1] if j + 1 < n else 0
      segmentCount = 1 + leftCount + rightCount

      # update sum and count of segment [l, r]
      l = j - leftCount
      r = j + rightCount
      sum[l] = segmentSum
      sum[r] = segmentSum
      count[l] = segmentCount
      count[r] = segmentCount
      maxSum = max(maxSum, segmentSum)

    return ans
