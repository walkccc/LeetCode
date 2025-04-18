class Solution:
  def distanceBetweenBusStops(
      self,
      distance: list[int],
      start: int, destination: int,
  ) -> int:
    clockwise = 0
    counterclockwise = 0

    if start > destination:
      start, destination = destination, start

    for i, d in enumerate(distance):
      if i >= start and i < destination:
        clockwise += d
      else:
        counterclockwise += d

    return min(clockwise, counterclockwise)
