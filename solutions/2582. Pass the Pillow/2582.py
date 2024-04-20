class Solution:
  def passThePillow(self, n: int, time: int) -> int:
    # Repeat every (n - 1) * 2 seconds.
    time %= (n - 1) * 2
    if time < n:  # Go forward from 1.
      return 1 + time
    return n - (time - (n - 1))  # Go backward from n.
