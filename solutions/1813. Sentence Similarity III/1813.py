class Solution:
  def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
    if len(sentence1) == len(sentence2):
      return sentence1 == sentence2

    words1 = sentence1.split()
    words2 = sentence2.split()
    m, n = map(len, (words1, words2))
    if m > n:
      return self.areSentencesSimilar(sentence2, sentence1)

    i = 0  # words1's index
    while i < m and words1[i] == words2[i]:
      i += 1
    while i < m and words1[i] == words2[i + n - m]:
      i += 1

    return i == m
