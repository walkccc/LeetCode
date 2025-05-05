class Solution:
  def ladderLength(
      self,
      beginWord: str,
      endWord: str,
      wordList: list[str],
  ) -> int:
    wordSet = set(wordList)
    if endWord not in wordSet:
      return 0

    q = collections.deque([beginWord])

    step = 1
    while q:
      for _ in range(len(q)):
        wordList = list(q.popleft())
        for i, cache in enumerate(wordList):
          for c in string.ascii_lowercase:
            wordList[i] = c
            word = ''.join(wordList)
            if word == endWord:
              return step + 1
            if word in wordSet:
              q.append(word)
              wordSet.remove(word)
          wordList[i] = cache
      step += 1

    return 0
