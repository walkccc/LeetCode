class Solution:
  def numberOfSpecialChars(self, word: str) -> int:
    lower = collections.defaultdict(bool)
    upper = collections.defaultdict(bool)

    for c in word:
      if c.islower():
        lower[c] = True
      else:
        upper[c] = True

    return sum(lower[a] and upper[b]
               for a, b in zip(string.ascii_lowercase,
                               string.ascii_uppercase))
