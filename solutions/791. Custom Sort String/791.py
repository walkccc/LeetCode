class Solution:
  def customSortString(self, order: str, s: str) -> str:
    ans = ""
    count = [0] * 26

    for c in s:
      count[string.ascii_lowercase.index(c)] += 1

    for c in order:
      while count[string.ascii_lowercase.index(c)] > 0:
        ans += c
        count[string.ascii_lowercase.index(c)] -= 1

    for c in string.ascii_lowercase:
      for _ in range(count[string.ascii_lowercase.index(c)]):
        ans += c

    return ans
