from sortedcontainers import SortedSet


class Solution:
  def generateSentences(
      self,
      synonyms: list[list[str]],
      text: str,
  ) -> list[str]:
    ans = SortedSet()
    graph = collections.defaultdict(list)
    q = collections.deque([text])

    for s, t in synonyms:
      graph[s].append(t)
      graph[t].append(s)

    while q:
      u = q.popleft()
      ans.add(u)
      words = u.split()
      for i, word in enumerate(words):
        for synonym in graph[word]:
          # Replace words[i] with its synonym.
          words[i] = synonym
          newText = ' '.join(words)
          if newText not in ans:
            q.append(newText)

    return list(ans)
