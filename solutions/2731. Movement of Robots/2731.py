class Solution:
  def sumDistance(self, nums: list[int], s: str, d: int) -> int:
    kMod = 1_000_000_007
    ans = 0
    prefix = 0
    pos = sorted([num - d if c == 'L' else num + d
                  for num, c in zip(nums, s)])

    for i, p in enumerate(pos):
      ans = ((ans + i * p - prefix) % kMod + kMod) % kMod
      prefix = ((prefix + p) % kMod + kMod) % kMod

    return ans
