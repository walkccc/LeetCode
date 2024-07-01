class Solution:
  def closestToTarget(self, arr: List[int], target: int) -> int:
    ans = math.inf
    dp = set()  # all the values of subarrays that end in the current number

    for num in arr:
      # Extend each subarray that ends in the dpious number. Due to
      # monotonicity of the AND operation, the size of `next_set` will be at most
      # bin(num).count('1') + 1.
      dp = {num} | {val & num for val in dp}
      ans = min(ans, min(abs(target - val) for val in dp))

    return ans
