class Solution:
  def minimizeConcatenatedLength(self, words: list[str]) -> int:
    @functools.lru_cache(None)
    def dp(i: int, first: str, last: str) -> int:
      """
      Returns the minimum concatenated length of the first i words starting with
      `first` and ending in `last`.
      """
      if i == len(words):
        return 0
      nextFirst = words[i][0]
      nextLast = words[i][-1]
      return len(words[i]) + min(
          # join(words[i - 1], words[i])
          dp(i + 1, first, nextLast) - (last == nextFirst),
          # join(words[i], words[i - 1])
          dp(i + 1, nextFirst, last) - (first == nextLast)
      )

    return len(words[0]) + dp(1, words[0][0], words[0][-1])
