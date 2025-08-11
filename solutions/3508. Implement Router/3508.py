from dataclasses import dataclass


@dataclass(frozen=True)
class Packet:
  source: int
  destination: int
  timestamp: int


class Router:
  def __init__(self, memoryLimit: int):
    self.memoryLimit = memoryLimit
    self.uniquePackets: set[Packet] = set()
    self.packetQueue: collections.deque[Packet] = collections.deque()
    self.destinationTimestamps = collections.defaultdict(list)
    self.processedPacketIndex = collections.Counter()

  def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
    packet = Packet(source, destination, timestamp)
    if packet in self.uniquePackets:
      return False
    if len(self.packetQueue) == self.memoryLimit:
      self.forwardPacket()
    self.packetQueue.append(packet)
    self.uniquePackets.add(packet)
    if destination not in self.destinationTimestamps:
      self.destinationTimestamps[destination] = []
    self.destinationTimestamps[destination].append(timestamp)
    return True

  def forwardPacket(self) -> list[int]:
    if not self.packetQueue:
      return []
    nextPacket = self.packetQueue.popleft()
    self.uniquePackets.remove(nextPacket)
    self.processedPacketIndex[nextPacket.destination] += 1
    return [nextPacket.source, nextPacket.destination, nextPacket.timestamp]

  def getCount(self, destination: int, startTime: int, endTime: int) -> int:
    if destination not in self.destinationTimestamps:
      return 0
    timestamps = self.destinationTimestamps[destination]
    startIndex = self.processedPacketIndex.get(destination, 0)
    lowerBound = bisect.bisect_left(timestamps, startTime, startIndex)
    upperBound = bisect.bisect_right(timestamps, endTime, startIndex)
    return upperBound - lowerBound
