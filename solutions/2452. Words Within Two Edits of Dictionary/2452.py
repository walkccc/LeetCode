class Solution:
  def twoEditWords(
      self,
      queries: list[str],
      dictionary: list[str],
  ) -> list[str]:
    return [query for query in queries
            if any(sum(a != b for a, b in zip(query, word)) < 3
                   for word in dictionary)]
