class Solution:
  def countNonDecreasingSubarrays(self, nums: list[int], k: int) -> int:
    ans = 0
    cost = 0
    # Store (number, count) pairs in non-increasing order. The numbers in the
    # queue represent what nums[i..j] look like after adjustments.
    dq = collections.deque()

    j = len(nums) - 1
    for i, num in reversed(list(enumerate(nums))):
      count = 1
      while dq and dq[-1][0] < num:
        nextNum, nextCount = dq.pop()
        count += nextCount
        cost += (num - nextNum) * nextCount  # Adjust `nextNum`s to `num`.
      dq.append((num, count))
      while cost > k:  # Remove the rightmost number.
        rightmostNum, rightmostCount = dq.popleft()
        cost -= (rightmostNum - nums[j])
        j -= 1
        if rightmostCount > 1:
          dq.appendleft((rightmostNum, rightmostCount - 1))
      ans += j - i + 1

    return ans
