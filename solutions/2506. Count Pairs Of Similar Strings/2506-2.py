class Solution:
  def similarPairs(self, words: list[str]) -> int:
    return sum(set(words[i]) == set(words[j])
               for i, j in itertools.combinations(range(len(words)), 2))
