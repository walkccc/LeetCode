class Solution:
  def validWordAbbreviation(self, word: str, abbr: str) -> bool:
    i = 0  # word's index
    j = 0  # abbr's index

    while i < len(word) and j < len(abbr):
      if word[i] == abbr[j]:
        i += 1
        j += 1
        continue
      if not abbr[j].isdigit() or abbr[j] == '0':
        return False
      num = 0
      while j < len(abbr) and abbr[j].isdigit():
        num = num * 10 + int(abbr[j])
        j += 1
      i += num

    return i == len(word) and j == len(abbr)
