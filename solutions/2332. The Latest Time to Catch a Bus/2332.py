class Solution:
  def latestTimeCatchTheBus(
      self,
      buses: list[int],
      passengers: list[int],
      capacity: int,
  ) -> int:
    buses.sort()
    passengers.sort()

    if passengers[0] > buses[-1]:
      return buses[-1]

    ans = passengers[0] - 1
    i = 0  # buses' index
    j = 0  # passengers' index

    while i < len(buses):
      # Greedily make passengers catch `buses[i]`.
      arrived = 0
      while arrived < capacity and j < len(passengers) and passengers[j] <= buses[i]:
        if j > 0 and passengers[j] != passengers[j - 1] + 1:
          ans = passengers[j] - 1
        j += 1
        arrived += 1
      # There's room for `buses[i]` to carry a passenger arriving at the
      # `buses[i]`.
      if arrived < capacity and j > 0 and passengers[j - 1] != buses[i]:
        ans = buses[i]
      i += 1

    return ans
