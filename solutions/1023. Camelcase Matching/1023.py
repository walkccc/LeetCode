class Solution:
  def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
    def isMatch(query: str) -> bool:
      j = 0

      for i, c in enumerate(query):
        if j < len(pattern) and c == pattern[j]:
          j += 1
        elif c.isupper():
          return False

      return j == len(pattern)

    return [isMatch(query) for query in queries]
