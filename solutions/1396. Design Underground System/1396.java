class CheckIn {
  public String stationName;
  public int t;

  public CheckIn(String stationName, int t) {
    this.stationName = stationName;
    this.t = t;
  }
}

class CheckOut {
  public int nTrips;
  public int totalTime;

  public CheckOut(int nTrips, int totalTime) {
    this.nTrips = nTrips;
    this.totalTime = totalTime;
  }
}

class UndergroundSystem {
  public void checkIn(int id, String stationName, int t) {
    checkIns.put(id, new CheckIn(stationName, t));
  }

  public void checkOut(int id, String stationName, int t) {
    final CheckIn checkIn = checkIns.get(id);
    checkIns.remove(id);
    final String key = checkIn.stationName + "->" + stationName;
    checkOuts.putIfAbsent(key, new CheckOut(0, 0));
    ++checkOuts.get(key).nTrips;
    checkOuts.get(key).totalTime += t - checkIn.t;
  }

  public double getAverageTime(String startStation, String endStation) {
    final CheckOut checkOut = checkOuts.get(startStation + "->" + endStation);
    return checkOut.totalTime / (double) checkOut.nTrips;
  }

  private Map<Integer, CheckIn> checkIns = new HashMap<>(); // {stationName, time}
  private Map<String, CheckOut> checkOuts = new HashMap<>(); // {nTrips, totalTime}
}
