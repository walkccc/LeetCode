class Solution:
  def customSortString(self, order: str, s: str) -> str:
    ans = ""
    count = [0] * 26

    for c in s:
      count[ord(c) - ord('a')] += 1

    for c in order:
      while count[ord(c) - ord('a')] > 0:
        ans += c
        count[ord(c) - ord('a')] -= 1

    for c in string.ascii_lowercase:
      for _ in range(count[ord(c) - ord('a')]):
        ans += c

    return ans
