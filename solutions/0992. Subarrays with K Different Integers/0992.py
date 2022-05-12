class Solution:
  def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
    def subarraysWithAtMostKDistinct(K: int) -> int:
      ans = 0
      count = Counter()

      l = 0
      for r, a in enumerate(A):
        count[a] += 1
        if count[a] == 1:
          K -= 1
        while K < 0:
          count[A[l]] -= 1
          if count[A[l]] == 0:
            K += 1
          l += 1
        ans += r - l + 1  # A[l..r], A[l + 1..r], ..., A[r]

      return ans

    return subarraysWithAtMostKDistinct(K) - subarraysWithAtMostKDistinct(K - 1)
