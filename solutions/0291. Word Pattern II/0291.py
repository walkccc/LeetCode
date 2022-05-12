class Solution:
  def wordPatternMatch(self, pattern: str, s: str) -> bool:
    def isMatch(i: int, j: int, charToString: Dict[chr, str], seen: Set[str]) -> bool:
      if i == len(pattern) and j == len(s):
        return True
      if i == len(pattern) or j == len(s):
        return False

      c = pattern[i]

      if c in charToString:
        t = charToString[c]
        # check if we can match t w// s[j..j + len(t))
        if t not in s[j:]:
          return False

        # if can match, so continue match the rest
        return isMatch(i + 1, j + len(t), charToString, seen)

      for k in range(j, len(s)):
        t = s[j:k + 1]

        # this is already mapped by other character
        if t in seen:
          continue

        charToString[c] = t
        seen.add(t)

        if isMatch(i + 1, k + 1, charToString, seen):
          return True

        # backtracking
        del charToString[c]
        seen.remove(t)

      return False

    return isMatch(0, 0, {}, set())
