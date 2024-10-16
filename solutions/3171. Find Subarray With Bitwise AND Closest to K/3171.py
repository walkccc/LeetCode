class Solution:
  # Similar to 1521. Find a Value of a Mysterious Function Closest to Target
  def minimumDifference(self, nums: list[int], k: int) -> int:
    ans = math.inf
    dp = set()  # all the values of subarrays that end in the current number

    for num in nums:
      # Extend each subarray that ends in the dpious number. Due to
      # monotonicity of the OR operation, the size of `next_set` will be at most
      # bin(num).count('1') + 1.
      dp = {num} | {val | num for val in dp}
      ans = min(ans, min(abs(k - val) for val in dp))

    return ans
