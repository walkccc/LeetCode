class Solution:
  def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
    divisorLcm = math.lcm(divisor1, divisor2)
    l = 0
    r = 2**31 - 1

    # True if we can take uniqueCnt1 integers from [1..m] to arr1 and take
    # uniqueCnt2 integers from [1..m] to arr2.
    def isPossible(m: int) -> bool:
      cnt1 = m - m // divisor1
      cnt2 = m - m // divisor2
      totalCnt = m - m // divisorLcm
      return cnt1 >= uniqueCnt1 and cnt2 >= uniqueCnt2 and \
          totalCnt >= uniqueCnt1 + uniqueCnt2

    while l < r:
      m = (l + r) // 2
      if isPossible(m):
        r = m
      else:
        l = m + 1

    return l
