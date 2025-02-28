class Solution:
  def areSentencesSimilar(
      self,
      sentence1: list[str],
      sentence2: list[str],
      similarPairs: list[list[str]],
  ) -> bool:
    if len(sentence1) != len(sentence2):
      return False

    # map[key] := all the similar words of key
    map = collections.defaultdict(set)

    for a, b in similarPairs:
      map[a].add(b)
      map[b].add(a)

    for word1, word2 in zip(sentence1, sentence2):
      if word1 == word2:
        continue
      if word1 not in map:
        return False
      if word2 not in map[word1]:
        return False

    return True
