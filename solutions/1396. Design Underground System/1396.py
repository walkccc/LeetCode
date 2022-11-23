class UndergroundSystem:
  def __init__(self):
    # {id: (stationName, time)}
    self.checkIns = {}
    # {route: (numTrips, totalTime)}
    self.checkOuts = defaultdict(lambda: [0, 0])

  def checkIn(self, id: int, stationName: str, t: int) -> None:
    self.checkIns[id] = (stationName, t)

  def checkOut(self, id: int, stationName: str, t: int) -> None:
    startStation, startTime = self.checkIns.pop(id)
    route = (startStation, stationName)
    self.checkOuts[route][0] += 1
    self.checkOuts[route][1] += t - startTime

  def getAverageTime(self, startStation: str, endStation: str) -> float:
    numTrips, totalTime = self.checkOuts[(startStation, endStation)]
    return totalTime / numTrips
