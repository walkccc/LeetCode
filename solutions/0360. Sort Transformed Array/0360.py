class Solution:
  def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
    n = len(nums)
    upward = a > 0
    ans = [0] * n

    # the concavity of f only depends on a's sign
    def f(x: int, a: int, b: int, c: int) -> int:
      return (a * x + b) * x + c

    quad = [f(num, a, b, c) for num in nums]

    i = n - 1 if upward else 0
    l = 0
    r = n - 1
    while l <= r:
      if upward:  # maximum in both ends
        if quad[l] > quad[r]:
          ans[i] = quad[l]
          l += 1
        else:
          ans[i] = quad[r]
          r -= 1
        i -= 1
      else:  # minimum in both ends
        if quad[l] < quad[r]:
          ans[i] = quad[l]
          l += 1
        else:
          ans[i] = quad[r]
          r -= 1
        i += 1

    return ans
