class Solution:
  def longestWPI(self, hours: list[int]) -> int:
    ans = 0
    prefix = 0
    dict = {}

    for i in range(len(hours)):
      prefix += 1 if hours[i] > 8 else -1
      if prefix > 0:
        ans = i + 1
      else:
        if prefix not in dict:
          dict[prefix] = i
        if prefix - 1 in dict:
          ans = max(ans, i - dict[prefix - 1])

    return ans
