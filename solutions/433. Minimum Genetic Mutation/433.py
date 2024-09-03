class Solution:
  def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:
    bankSet = set(bank)
    if endGene not in bankSet:
      return -1

    kGenes = 'ACGT'
    ans = 0
    q = collections.deque([startGene])

    while q:
      ans += 1
      for _ in range(len(q)):
        wordList = list(q.popleft())
        for j, cache in enumerate(wordList):
          for c in kGenes:
            wordList[j] = c
            word = ''.join(wordList)
            if word == endGene:
              return ans
            if word in bankSet:
              bankSet.remove(word)
              q.append(word)
          wordList[j] = cache

    return -1
