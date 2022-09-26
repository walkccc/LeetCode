class Solution:
  def longestOnes(self, A: List[int], K: int) -> int:
    ans = 0

    l = 0
    for r, a in enumerate(A):
      if a == 0:
        K -= 1
      while K < 0:
        if A[l] == 0:
          K += 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
