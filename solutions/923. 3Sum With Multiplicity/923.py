class Solution:
  def threeSumMulti(self, arr: list[int], target: int) -> int:
    MOD = 1_000_000_007
    ans = 0
    count = collections.Counter(arr)

    for i, x in count.items():
      for j, y in count.items():
        k = target - i - j
        if k not in count:
          continue
        if i == j and j == k:
          ans = (ans + x * (x - 1) * (x - 2) // 6) % MOD
        elif i == j and j != k:
          ans = (ans + x * (x - 1) // 2 * count[k]) % MOD
        elif i < j and j < k:
          ans = (ans + x * y * count[k]) % MOD

    return ans % MOD
