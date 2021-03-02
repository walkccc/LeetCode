struct CheckIn {
  string stationName;
  int t;
};

struct CheckOut {
  int nTrips;
  int totalTime;
};

class UndergroundSystem {
 public:
  void checkIn(int id, string stationName, int t) {
    checkIns[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const CheckIn checkIn = checkIns[id];
    checkIns.erase(id);
    const string& key = checkIn.stationName + "->" + stationName;
    ++checkOuts[key].nTrips;
    checkOuts[key].totalTime += t - checkIn.t;
  }

  double getAverageTime(string startStation, string endStation) {
    const auto& [nTrips, totalTime] =
        checkOuts[startStation + "->" + endStation];
    return totalTime / (double)nTrips;
  }

 private:
  unordered_map<int, CheckIn> checkIns;       // {stationName, time}
  unordered_map<string, CheckOut> checkOuts;  // {nTrips, totalTime}
};
