class Solution:
  def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
    kCroak = 'croak'
    ans = 0
    frogs = 0
    count = [0] * 5

    for c in croakOfFrogs:
      count[kCroak.index(c)] += 1
      if any(count[i] > count[i - 1] for i in range(1, 5)):
        return -1
      if c == 'c':
        frogs += 1
      elif c == 'k':
        frogs -= 1
      ans = max(ans, frogs)

    return ans if frogs == 0 else -1
