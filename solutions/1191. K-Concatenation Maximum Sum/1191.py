class Solution:
  def kConcatenationMaxSum(self, arr: list[int], k: int) -> int:
    kMod = 1_000_000_007
    sz = len(arr) * (1 if k == 1 else 2)
    summ = sum(arr)
    # The concatenated array will be [arr1, arr2, ..., arrk].
    # If sum(arr) > 0 and k > 2, then arr2, ..., arr(k - 1) should be included.
    # Equivalently, maxSubarraySum is from arr1 and arrk.
    if summ > 0 and k > 2:
      return (self.kadane(arr, sz) + summ * (k - 2)) % kMod
    return self.kadane(arr, sz) % kMod

  def kadane(self, A: list[int], sz: int) -> int:
    ans = 0
    summ = 0
    for i in range(sz):
      a = A[i % len(A)]
      summ = max(a, summ + a)
      ans = max(ans, summ)
    return ans
