class Solution:
  def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:
    bankSet = set(bank)
    if endGene not in bankSet:
      return -1

    GENES = 'ACGT'
    q = collections.deque([startGene])

    step = 1
    while q:
      for _ in range(len(q)):
        wordList = list(q.popleft())
        for j, cache in enumerate(wordList):
          for c in GENES:
            wordList[j] = c
            word = ''.join(wordList)
            if word == endGene:
              return step
            if word in bankSet:
              bankSet.remove(word)
              q.append(word)
          wordList[j] = cache
      step += 1

    return -1
