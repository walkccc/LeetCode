class Solution:
  def canArrange(self, arr: list[int], k: int) -> bool:
    count = [0] * k

    for a in arr:
      a %= k
      count[a if a >= 0 else a + k] += 1

    return (count[0] % 2 == 0 and
            all(count[i] == count[k - i]
                for i in range(1, k // 2 + 1)))
