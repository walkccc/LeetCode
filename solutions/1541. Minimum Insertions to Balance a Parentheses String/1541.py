class Solution:
  def minInsertions(self, s: str) -> int:
    neededRight = 0   # Increment by 2 for each '('.
    missingLeft = 0   # Increment by 1 for each missing '('.
    missingRight = 0  # Increment by 1 for each missing ')'.

    for c in s:
      if c == '(':
        if neededRight % 2 == 1:
          # e.g. '()(...'
          missingRight += 1
          neededRight -= 1
        neededRight += 2
      else:  # c == ')'
        neededRight -= 1
        if neededRight < 0:
          # e.g. '()))...'
          missingLeft += 1
          neededRight += 2

    return neededRight + missingLeft + missingRight
