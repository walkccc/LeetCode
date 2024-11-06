class Solution:
  def checkIfPangram(self, sentence: str) -> bool:
    seen = 0

    for c in sentence:
      seen |= 1 << string.ascii_lowercase.index(c)

    return seen == (1 << 26) - 1
