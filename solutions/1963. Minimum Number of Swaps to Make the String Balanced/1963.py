class Solution:
  def minSwaps(self, s: str) -> int:
    # Cancel out all the matched pairs, then we'll be left with ']]]..[[['.
    # The answer is ceil(# of unmatched pairs // 2).
    unmatched = 0

    for c in s:
      if c == '[':
        unmatched += 1
      elif unmatched > 0:  # c == ']' and there's a match.
        unmatched -= 1

    return (unmatched + 1) // 2
