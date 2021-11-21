class Solution:
  def threeSumMulti(self, A: List[int], target: int) -> int:
    kMod = int(1e9 + 7)

    ans = 0
    count = Counter(A)

    for i, x in count.items():
      for j, y in count.items():
        k = target - i - j
        if k not in count:
          continue
        if i == j and j == k:
          ans += x * (x - 1) * (x - 2) // 6
        elif i == j and j != k:
          ans += x * (x - 1) // 2 * count[k]
        elif i < j and j < k:
          ans += x * y * count[k]

    return ans % kMod
