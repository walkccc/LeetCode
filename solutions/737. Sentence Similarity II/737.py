class Solution:
  def areSentencesSimilarTwo(
      self,
      words1: list[str],
      words2: list[str],
      pairs: list[list[str]],
  ) -> bool:
    if len(words1) != len(words2):
      return False

    # graph[key] := all the similar words of key
    graph = collections.defaultdict(set)

    for a, b in pairs:
      graph[a].add(b)
      graph[b].add(a)

    def dfs(word1: str, word2: str, seen: set) -> bool:
      if word1 in graph[word2]:
        return True

      seen.add(word1)

      for child in graph[word1]:
        if child in seen:
          continue
        if dfs(child, word2, seen):
          return True

      return False

    for word1, word2 in zip(words1, words2):
      if word1 == word2:
        continue
      if word1 not in graph:
        return False
      if not dfs(word1, word2, set()):
        return False

    return True
