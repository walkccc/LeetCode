class Solution:
  def closestToTarget(self, arr: list[int], target: int) -> int:
    ans = math.inf
    dp = set()  # all the values of subarrays that end in the current number

    for num in arr:
      # Extend each subarray that ends in the dpious number. Due to
      # monotonicity of the AND operation, the size of `dp` will be at most
      # num.bit_count() + 1.
      dp = {num} | {val & num for val in dp}
      ans = min(ans, min(abs(target - val) for val in dp))

    return ans
