class Solution:
  def maxNumberOfFamilies(self, n: int, reservedSeats: list[list[int]]) -> int:
    ans = 0
    rowToSeats = collections.Counter()

    for row, seat in reservedSeats:
      rowToSeats[row] |= 1 << (seat - 1)

    for seats in rowToSeats.values():
      if (seats & 0b0111111110) == 0:
        # Can fit 2 four-person groups.
        ans += 2
      elif ((seats & 0b0111100000) == 0 or
            (seats & 0b0001111000) == 0 or
            (seats & 0b0000011110) == 0):
        # Can fit 1 four-person group.
        ans += 1

    # Any empty row can fit 2 four-person groups.
    return ans + (n - len(rowToSeats)) * 2
