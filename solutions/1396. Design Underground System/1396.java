class CheckIn {
  public String stationName;
  public int time;
  public CheckIn(String stationName, int time) {
    this.stationName = stationName;
    this.time = time;
  }
}

class CheckOut {
  public int numTrips;
  public int totalTime;
  public CheckOut(int numTrips, int totalTime) {
    this.numTrips = numTrips;
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
    final String route = checkIn.stationName + "->" + stationName;
    checkOuts.putIfAbsent(route, new CheckOut(0, 0));
    ++checkOuts.get(route).numTrips;
    checkOuts.get(route).totalTime += t - checkIn.time;
  }

  public double getAverageTime(String startStation, String endStation) {
    final CheckOut checkOut = checkOuts.get(startStation + "->" + endStation);
    return checkOut.totalTime / (double) checkOut.numTrips;
  }

  private Map<Integer, CheckIn> checkIns = new HashMap<>();  // {id: (stationName, time)}
  private Map<String, CheckOut> checkOuts = new HashMap<>(); // {route: (numTrips, totalTime)}
}
