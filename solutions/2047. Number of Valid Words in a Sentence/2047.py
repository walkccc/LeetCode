class Solution:
  def countValidWords(self, sentence: str) -> int:
    def isValid(token: str) -> bool:
      countHyphen = 0
      for i, c in enumerate(token):
        if c.isdigit():
          return False
        if c == '-':
          if i == 0 or not token[i - 1].isalpha():
            return False
          if i == len(token) - 1 or not token[i + 1].isalpha():
            return False
          if countHyphen == 1:
            return False
          countHyphen += 1
        if c in ['!', '.', ',']:
          if i != len(token) - 1:
            return False
      return True

    return sum(isValid(token) for token in sentence.split())
