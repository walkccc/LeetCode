class Solution:
  def numberOfWays(self, corridor: str) -> int:
    kMod = int(1e9) + 7
    ans = 1
    prevSeat = -1
    numSeats = 0

    for i, c in enumerate(corridor):
      if c == 'S':
        numSeats += 1
        if numSeats > 2 and numSeats & 1:
          ans = ans * (i - prevSeat) % kMod
        prevSeat = i

    return ans if numSeats > 1 and numSeats % 2 == 0 else 0
