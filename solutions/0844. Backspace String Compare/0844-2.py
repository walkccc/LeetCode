class Solution:
  def backspaceCompare(self, s: str, t: str) -> bool:
    i = len(s) - 1  # s's index
    j = len(t) - 1  # t's index

    while True:
      # Delete characters of s if needed.
      backspace = 0
      while i >= 0 and (s[i] == '#' or backspace > 0):
        backspace += 1 if s[i] == '#' else -1
        i -= 1
      # Delete characters of t if needed.
      backspace = 0
      while j >= 0 and (t[j] == '#' or backspace > 0):
        backspace += 1 if t[j] == '#' else -1
        j -= 1
      if i >= 0 and j >= 0 and s[i] == t[j]:
        i -= 1
        j -= 1
      else:
        break

    return i == -1 and j == -1
