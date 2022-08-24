class Solution:
  def reverseOnlyLetters(self, S: str) -> str:
    S = list(S)
    i = 0
    j = len(S) - 1

    while i < j:
      while i < j and not S[i].isalpha():
        i += 1
      while i < j and not S[j].isalpha():
        j -= 1
      S[i], S[j] = S[j], S[i]
      i += 1
      j -= 1

    return ''.join(S)
