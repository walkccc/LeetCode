class Solution:
  def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
    wordSet = set(wordList)
    if endWord not in wordList:
      return []

    # {"hit": ["hot"], "hot": ["dot", "lot"], ...}
    graph: Dict[str, List[str]] = collections.defaultdict(list)

    # Build the graph from the beginWord to the endWord.
    if not self._bfs(beginWord, endWord, wordSet, graph):
      return []

    ans = []

    self._dfs(graph, beginWord, endWord, [beginWord], ans)
    return ans

  def _bfs(self, beginWord: str, endWord: str, wordSet: Set[str], graph: Dict[str, List[str]]) -> bool:
    q1 = {beginWord}
    q2 = {endWord}
    backward = False

    while q1 and q2:
      for word in q1:
        wordSet.discard(word)
      for word in q2:
        wordSet.discard(word)
      # Always expand the smaller queue.
      if len(q1) > len(q2):
        q1, q2 = q2, q1
        backward = not backward
      q = set()
      reachEndWord = False
      for parent in q1:
        for child in self._getChildren(parent, wordSet, q2):
          if child in wordSet or child in q2:
            q.add(child)
            if backward:
              graph[child].append(parent)
            else:
              graph[parent].append(child)
          if child in q2:
            reachEndWord = True
      if reachEndWord:
        return True
      q1 = q

    return False

  def _getChildren(self, parent: str, wordSet: Set[str], q2) -> List[str]:
    children = []
    s = list(parent)

    for i, cache in enumerate(s):
      for c in string.ascii_lowercase:
        if c == cache:
          continue
        s[i] = c
        child = ''.join(s)
        if child in wordSet or child in q2:
          children.append(child)
      s[i] = cache

    return children

  def _dfs(self, graph: Dict[str, List[str]], word: str, endWord: str, path: List[str], ans: List[List[str]]) -> None:
    if word == endWord:
      ans.append(path.copy())
      return

    for child in graph.get(word, []):
      path.append(child)
      self._dfs(graph, child, endWord, path, ans)
      path.pop()
