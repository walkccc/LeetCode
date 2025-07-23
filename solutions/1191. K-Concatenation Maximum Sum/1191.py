class Solution:
  def kConcatenationMaxSum(self, arr: list[int], k: int) -> int:
    MOD = 1_000_000_007
    sz = len(arr) * (1 if k == 1 else 2)
    summ = sum(arr)
    # The concatenated array will be [arr1, arr2, ..., arrk].
    # If sum(arr) > 0 and k > 2, then arr2, ..., arr(k - 1) should be included.
    # Equivalently, maxSubarraySum is from arr1 and arrk.
    if summ > 0 and k > 2:
      return (self._kadane(arr, sz) + summ * (k - 2)) % MOD
    return self._kadane(arr, sz) % MOD

  def _kadane(self, arr: list[int], sz: int) -> int:
    ans = 0
    summ = 0
    for i in range(sz):
      a = arr[i % len(arr)]
      summ = max(a, summ + a)
      ans = max(ans, summ)
    return ans
