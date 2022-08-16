class Solution:
  def singleDivisorTriplet(self, nums: List[int]) -> int:
    ans = 0
    count = Counter(nums)

    def divisible(sum: int, num: int) -> int:
      return sum % num == 0

    for a in range(1, 101):
      if count[a] == 0:
        continue
      for b in range(a, 101):
        if count[b] == 0:
          continue
        for c in range(b, 101):
          if count[c] == 0:
            continue
          sum = a + b + c
          if divisible(sum, a) + divisible(sum, b) + divisible(sum, c) != 1:
            continue
          if a == b:
            ans += count[a] * (count[a] - 1) // 2 * count[c]
          elif b == c:
            ans += count[b] * (count[b] - 1) // 2 * count[a]
          else:
            ans += count[a] * count[b] * count[c]

    return ans * 6
