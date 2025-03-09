class Solution:
  def sumDistance(self, nums: list[int], s: str, d: int) -> int:
    MOD = 1_000_000_007
    ans = 0
    prefix = 0
    pos = sorted([num - d if c == 'L' else num + d
                  for num, c in zip(nums, s)])

    for i, p in enumerate(pos):
      ans = ((ans + i * p - prefix) % MOD + MOD) % MOD
      prefix = ((prefix + p) % MOD + MOD) % MOD

    return ans
