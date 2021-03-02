class Solution:
  def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
    wordSet = set(wordList)
    if endWord not in wordSet:
      return 0

    ans = 0
    q = deque([beginWord])
    beginWordList = list(beginWord)

    while q:
      ans += 1
      for _ in range(len(q)):
        wordList = list(q.popleft())
        for i, cache in enumerate(wordList):
          for c in string.ascii_lowercase:
            wordList[i] = c
            word = ''.join(wordList)
            if ''.join(word) == endWord:
              return ans + 1
            if word in wordSet:
              wordSet.remove(word)
              q.append(word)
          wordList[i] = cache

    return 0
