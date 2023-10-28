class Solution:
  def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
    wordSet = set(wordList)
    if endWord not in wordSet:
      return 0

    ans = 0
    q = collections.deque([beginWord])

    while q:
      ans += 1
      for _ in range(len(q)):
        wordList = list(q.popleft())
        for i, cache in enumerate(wordList):
          for c in string.ascii_lowercase:
            wordList[i] = c
            word = ''.join(wordList)
            if word == endWord:
              return ans + 1
            if word in wordSet:
              q.append(word)
              wordSet.remove(word)
          wordList[i] = cache

    return 0
