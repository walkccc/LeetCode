class Solution:
  def isAlienSorted(self, words: list[str], order: str) -> bool:
    dict = {c: i for i, c in enumerate(order)}
    words = [[dict[c] for c in word] for word in words]
    return all(w1 <= w2 for w1, w2 in zip(words, words[1:]))
