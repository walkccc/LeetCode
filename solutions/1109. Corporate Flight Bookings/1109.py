class Solution:
  def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
    ans = [0] * n

    for booking in bookings:
      ans[booking[0] - 1] += booking[2]
      if booking[1] < n:
        ans[booking[1]] -= booking[2]

    for i in range(1, n):
      ans[i] += ans[i - 1]

    return ans
