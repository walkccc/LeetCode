class Solution:
  def numOfStrings(self, patterns: list[str], word: str) -> int:
    return sum(pattern in word for pattern in patterns)
