class Solution:
  def maximumNumberOfStringPairs(self, words: List[str]) -> int:
    ans = 0
    seen = [False] * (26 * 26)

    def val(c: str) -> int:
      return ord(c) - ord('a')

    for word in words:
      if seen[val(word[1]) * 26 + val(word[0])]:
        ans += 1
      seen[val(word[0]) * 26 + val(word[1])] = True

    return ans
