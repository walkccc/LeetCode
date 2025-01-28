class Solution:
  def countPartitions(self, nums: list[int]) -> int:
    # If we add the same number in the left subarray and remove it from the
    # right subarray, then the difference remains the same parity. So, just
    # return the number of ways to partition the array into two subarrays when
    # the array sum is even.
    return len(nums) - 1 if sum(nums) % 2 == 0 else 0
