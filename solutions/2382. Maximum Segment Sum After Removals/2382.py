class Solution:
  def maximumSegmentSum(
      self,
      nums: list[int],
      removeQueries: list[int],
  ) -> list[int]:
    n = len(nums)
    maxSum = 0
    ans = [0] * n
    # For the segment [l, r], record its sum in summ[l] and summ[r]
    summ = [0] * n
    # For the segment [l, r], record its count in count[l] and count[r]
    count = [0] * n

    for i in reversed(range(n)):
      ans[i] = maxSum
      j = removeQueries[i]

      # Calculate `segmentSum`.
      leftSum = summ[j - 1] if j > 0 else 0
      rightSum = summ[j + 1] if j + 1 < n else 0
      segmentSum = nums[j] + leftSum + rightSum

      # Calculate `segmentCount`.
      leftCount = count[j - 1] if j > 0 else 0
      rightCount = count[j + 1] if j + 1 < n else 0
      segmentCount = 1 + leftCount + rightCount

      # Update `summ` and `count` of the segment [l, r].
      l = j - leftCount
      r = j + rightCount
      summ[l] = segmentSum
      summ[r] = segmentSum
      count[l] = segmentCount
      count[r] = segmentCount
      maxSum = max(maxSum, segmentSum)

    return ans
