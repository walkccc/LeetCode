class Solution:
  # Similar to 1521. Find a Value of a Mysterious Function Closest to Target
  def countSubarrays(self, nums: list[int], k: int) -> int:
    ans = 0
    # the counter of all the values of subarrays that end in the previous
    # number
    prev = collections.Counter()

    for num in nums:
      # Extend each subarray that ends in the previous number. Due to
      # monotonicity of the AND operation, the size of `curr` will be at most
      # num.bit_count() + 1.
      curr = collections.Counter({num: 1})
      for val, freq in prev.items():
        curr[val & num] += freq
      ans += curr[k]
      prev = curr

    return ans
