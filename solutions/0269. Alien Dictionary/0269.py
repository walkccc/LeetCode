class Solution:
  def alienOrder(self, words: List[str]) -> str:
    graph = {}
    inDegree = [0] * 26

    self._buildGraph(graph, words, inDegree)
    return self._topology(graph, inDegree)

  def _buildGraph(self, graph: Dict[chr, Set[chr]], words: List[str], inDegree: List[int]) -> None:
    # create node for each character in each word
    for word in words:
      for c in word:
        if c not in graph:
          graph[c] = set()

    for first, second in zip(words, words[1:]):
      length = min(len(first), len(second))
      for j in range(length):
        u = first[j]
        v = second[j]
        if u != v:
          if v not in graph[u]:
            graph[u].add(v)
            inDegree[ord(v) - ord('a')] += 1
          break  # later characters' order are meaningless
        # first = 'ab', second = 'a' . invalid
        if j == length - 1 and len(first) > len(second):
          graph.clear()
          return

  def _topology(self, graph: Dict[chr, Set[chr]], inDegree: List[int]) -> str:
    s = ''
    q = deque()

    for c in graph:
      if inDegree[ord(c) - ord('a')] == 0:
        q.append(c)

    while q:
      u = q.pop()
      s += u
      for v in graph[u]:
        inDegree[ord(v) - ord('a')] -= 1
        if inDegree[ord(v) - ord('a')] == 0:
          q.append(v)

    # words = ['z', 'x', 'y', 'x']
    return s if len(s) == len(graph) else ''
