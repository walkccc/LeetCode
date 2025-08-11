struct Packet {
  int source;
  int destination;
  int timestamp;

  bool operator<(const Packet& other) const {
    return source < other.source ||
           (source == other.source && destination < other.destination) ||
           (source == other.source && destination == other.destination &&
            timestamp < other.timestamp);
  }
};

class Router {
 public:
  Router(int memoryLimit) : memoryLimit(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    const Packet packet{source, destination, timestamp};
    if (uniquePackets.find(packet) != uniquePackets.end())
      return false;
    if (packetQueue.size() == memoryLimit)
      forwardPacket();
    packetQueue.push(packet);
    uniquePackets.insert(packet);
    destinationTimestamps[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    if (packetQueue.empty())
      return {};
    const Packet nextPacket = packetQueue.front();
    packetQueue.pop();
    uniquePackets.erase(nextPacket);
    ++processedPacketIndex[nextPacket.destination];
    return {nextPacket.source, nextPacket.destination, nextPacket.timestamp};
  }

  int getCount(int destination, int startTime, int endTime) {
    if (destinationTimestamps.find(destination) == destinationTimestamps.end())
      return 0;
    const vector<int>& timestamps = destinationTimestamps[destination];
    const int startIndex = processedPacketIndex[destination];
    const auto lowerBound = lower_bound(timestamps.begin() + startIndex,
                                        timestamps.end(), startTime);
    const auto upperBound =
        upper_bound(timestamps.begin() + startIndex, timestamps.end(), endTime);
    return upperBound - lowerBound;
  }

 private:
  const int memoryLimit;
  set<Packet> uniquePackets;
  queue<Packet> packetQueue;
  map<int, vector<int>> destinationTimestamps;
  map<int, int> processedPacketIndex;
};
