class Solution:
  def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
    return [query for query in queries
            if any(sum(a != b for a, b in zip(query, word)) < 3
                   for word in dictionary)]
