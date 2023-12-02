class Solution:
  def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
    return [self._isArithmetic(nums, a, b) for a, b in zip(l, r)]

  def _isArithmetic(self, nums: List[int], l: int, r: int) -> bool:
    if r - l < 2:
      return True

    numsSet = set()
    mini = math.inf
    maxi = -math.inf

    for i in range(l, r+1):
      mini = min(mini, nums[i])
      maxi = max(maxi, nums[i])
      numsSet.add(nums[i])

    if (maxi - mini) % (r - l) != 0:
      return False

    interval = (maxi - mini) // (r - l)
    return all(mini + k * interval in numsSet
               for k in range(1, r - l + 1))
