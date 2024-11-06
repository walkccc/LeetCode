class Solution:
  def minOperations(self, nums1: list[int], nums2: list[int], k: int) -> int:
    if k == 0:
      return 0 if nums1 == nums2 else -1

    ans = 0
    opsDiff = 0  # the number of increments - number of decrements

    for num1, num2 in zip(nums1, nums2):
      diff = num1 - num2
      if diff == 0:
        continue
      if diff % k != 0:
        return -1
      ops = diff // k
      opsDiff += ops
      ans += abs(ops)

    return ans // 2 if opsDiff == 0 else -1
