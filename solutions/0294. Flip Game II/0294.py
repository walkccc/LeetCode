class Solution:
  @functools.lru_cache(None)
  def canWin(self, currentState: str) -> bool:
    # If any of currentState[i:i + 2] == "++" and your friend can't win after
    # changing currentState[i:i + 2] to "--" (or "-"), then you can win.
    return any(True
               for i, (a, b) in enumerate(zip(currentState, currentState[1:]))
               if a == '+' and b == '+' and
               not self.canWin(currentState[:i] + '-' + currentState[i + 2:]))
