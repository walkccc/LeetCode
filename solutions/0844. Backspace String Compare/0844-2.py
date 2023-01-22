class Solution:
  def backspaceCompare(self, S: str, T: str) -> bool:
    i = len(S) - 1
    j = len(T) - 1

    while i >= 0 or j >= 0:
      backspace = 0
      while i >= 0 and (S[i] == '#' or backspace > 0):
        backspace += 1 if S[i] == '#' else -1
        i -= 1
      backspace = 0
      while j >= 0 and (T[j] == '#' or backspace > 0):
        backspace += 1 if T[j] == '#' else -1
        j -= 1
      if i >= 0 and j >= 0 and S[i] != T[j] or \
          i < 0 and j >= 0 and S[j] != '#' or \
              j < 0 and i >= 0 and S[i] != '#':
        return False
      i -= 1
      j -= 1

    return True
