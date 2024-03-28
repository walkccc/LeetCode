class Solution:
  def maxPower(self, stations: List[int], r: int, k: int) -> int:
    n = len(stations)
    left = min(stations)
    right = sum(stations) + k + 1

    # Returns true if each city can have at least `minPower`.
    def check(stations: List[int], additionalStations: int, minPower: int) -> bool:
      # Initilaize `power` as the 0-th city's power - stations[r].
      power = sum(stations[:r])

      for i in range(n):
        if i + r < n:
          power += stations[i + r]  # `power` = sum(stations[i - r..i + r]).
        if power < minPower:
          requiredPower = minPower - power
          # There're not enough stations to plant.
          if requiredPower > additionalStations:
            return False
          # Greedily plant `requiredPower` power stations in the farthest place
          # to cover as many cities as possible.
          stations[min(n - 1, i + r)] += requiredPower
          additionalStations -= requiredPower
          power += requiredPower
        if i - r >= 0:
          power -= stations[i - r]

      return True

    while left < right:
      mid = (left + right) // 2
      if check(stations.copy(), k, mid):
        left = mid + 1
      else:
        right = mid

    return left - 1
