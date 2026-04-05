class Solution:
  def splitWordsBySeparator(
      self,
      words: list[str],
      separator: str,
  ) -> list[str]:
    return [splitWord
            for word in words
            for splitWord in word.split(separator)
            if splitWord]
