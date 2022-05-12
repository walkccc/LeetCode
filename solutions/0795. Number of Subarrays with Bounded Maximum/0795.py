class Solution:
  def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
    ans = 0
    l = -1
    r = -1

    for i, a in enumerate(A):
      if a > R:
        l = i
      if a >= L:
        r = i
      ans += r - l

    return ans
