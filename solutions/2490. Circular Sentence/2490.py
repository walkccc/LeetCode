class Solution:
  def isCircularSentence(self, sentence: str) -> bool:
    for i, c in enumerate(sentence):
      if c == ' ' and sentence[i - 1] != sentence[i + 1]:
        return False
    return sentence[0] == sentence[-1]
