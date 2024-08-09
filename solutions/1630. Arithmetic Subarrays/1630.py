class Solution:
  def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
    return [self._isArithmetic(nums, a, b) for a, b in zip(l, r)]

  def _isArithmetic(self, nums: List[int], l: int, r: int) -> bool:
    if r - l < 2:
      return True

    numsSet = set()
    mn = math.inf
    mx = -math.inf

    for i in range(l, r+1):
      mn = min(mn, nums[i])
      mx = max(mx, nums[i])
      numsSet.add(nums[i])

    if (mx - mn) % (r - l) != 0:
      return False

    interval = (mx - mn) // (r - l)
    return all(mn + k * interval in numsSet
               for k in range(1, r - l + 1))
