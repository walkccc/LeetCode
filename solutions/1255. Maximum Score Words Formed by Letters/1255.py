class Solution:
  def maxScoreWords(
      self,
      words: list[str],
      letters: list[str],
      score: list[int],
  ) -> int:
    count = collections.Counter(letters)

    def useWord(i: int) -> int:
      isValid = True
      earned = 0
      for c in words[i]:
        count[c] -= 1
        if count[c] < 0:
          isValid = False
        earned += score[string.ascii_lowercase.index(c)]
      return earned if isValid else -1

    def unuseWord(i: int) -> None:
      for c in words[i]:
        count[c] += 1

    def dfs(s: int) -> int:
      """Returns the maximum score you can get from words[s..n)."""
      ans = 0
      for i in range(s, len(words)):
        earned = useWord(i)
        if earned > 0:
          ans = max(ans, earned + dfs(i + 1))
        unuseWord(i)
      return ans

    return dfs(0)
