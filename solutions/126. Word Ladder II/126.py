class Solution:
  def findLadders(self, beginWord: str, endWord: str, wordList: list[str]) -> list[list[str]]:
    wordSet = set(wordList)
    if endWord not in wordList:
      return []

    # {"hit": ["hot"], "hot": ["dot", "lot"], ...}
    graph: dict[str, list[str]] = collections.defaultdict(list)

    # Build the graph from the beginWord to the endWord.
    if not self._bfs(beginWord, endWord, wordSet, graph):
      return []

    ans = []
    self._dfs(graph, beginWord, endWord, [beginWord], ans)
    return ans

  def _bfs(
      self,
      beginWord: str,
      endWord: str,
      wordSet: set[str],
      graph: dict[str, list[str]],
  ) -> bool:
    currentLevelWords = {beginWord}

    while currentLevelWords:
      for word in currentLevelWords:
        wordSet.discard(word)
      nextLevelWords = set()
      reachEndWord = False
      for parent in currentLevelWords:
        for child in self._getChildren(parent, wordSet):
          if child in wordSet:
            nextLevelWords.add(child)
            graph[parent].append(child)
          if child == endWord:
            reachEndWord = True
      if reachEndWord:
        return True
      currentLevelWords = nextLevelWords

    return False

  def _getChildren(self, parent: str, wordSet: set[str]) -> list[str]:
    children = []
    s = list(parent)

    for i, cache in enumerate(s):
      for c in string.ascii_lowercase:
        if c == cache:
          continue
        s[i] = c
        child = ''.join(s)
        if child in wordSet:
          children.append(child)
      s[i] = cache

    return children

  def _dfs(
      self,
      graph: dict[str, list[str]],
      word: str,
      endWord: str,
      path: list[str],
      ans: list[list[str]],
  ) -> None:
    if word == endWord:
      ans.append(path.copy())
      return

    for child in graph.get(word, []):
      path.append(child)
      self._dfs(graph, child, endWord, path, ans)
      path.pop()
