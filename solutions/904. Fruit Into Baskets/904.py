class Solution:
  def totalFruit(self, fruits: list[int]) -> int:
    ans = 0
    count = collections.defaultdict(int)

    l = 0
    for r, fruit in enumerate(fruits):
      count[fruit] += 1
      while len(count) > 2:
        count[fruits[l]] -= 1
        if count[fruits[l]] == 0:
          del count[fruits[l]]
        l += 1
      ans = max(ans, r - l + 1)

    return ans
