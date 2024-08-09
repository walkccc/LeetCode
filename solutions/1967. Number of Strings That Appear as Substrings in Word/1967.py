class Solution:
  def numOfStrings(self, patterns: List[str], word: str) -> int:
    return sum(pattern in word for pattern in patterns)
