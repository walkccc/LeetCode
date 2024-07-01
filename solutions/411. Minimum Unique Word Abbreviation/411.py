class Solution:
  def minAbbreviation(self, target: str, dictionary: List[str]) -> str:
    m = len(target)

    def getMask(word: str) -> int:
      # mask[i] = 0 := target[i] == word[i]
      # mask[i] = 1 := target[i] != word[i]
      # e.g. target = "apple"
      #        word = "blade"
      #        mask =  11110
      mask = 0
      for i, c in enumerate(word):
        if c != target[i]:
          mask |= 1 << m - 1 - i
      return mask

    masks = [getMask(word) for word in dictionary if len(word) == m]
    if not masks:
      return str(m)

    abbrs = []

    def getAbbr(cand: int) -> str:
      abbr = []
      replacedCount = 0
      for i, c in enumerate(target):
        if cand >> m - 1 - i & 1:
          # If cand[i] = 1, `abbr` should show the original character.
          if replacedCount:
            abbr += str(replacedCount)
          abbr.append(c)
          replacedCount = 0
        else:
          # If cand[i] = 0, `abbr` can be replaced.
          replacedCount += 1
      if replacedCount:
        abbr.append(str(replacedCount))
      return ''.join(abbr)

    # all the candidate representation of the target
    for cand in range(2**m):
      # All the masks have at lease one bit different from the candidate.
      if all(cand & mask for mask in masks):
        abbr = getAbbr(cand)
        abbrs.append(abbr)

    def getAbbrLen(abbr: str) -> int:
      abbrLen = 0
      i = 0
      j = 0
      while i < len(abbr):
        if abbr[j].isalpha():
          j += 1
        else:
          while j < len(abbr) and abbr[j].isdigit():
            j += 1
        abbrLen += 1
        i = j
      return abbrLen

    return min(abbrs, key=lambda x: getAbbrLen(x))
