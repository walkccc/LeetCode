class Solution {
  public boolean carPooling(int[][] trips, int capacity) {
    int currentPassengers = 0;
    Map<Integer, Integer> timeline = new TreeMap<>();

    for (int[] trip : trips) {
      final int nPassengers = trip[0];
      final int start = trip[1];
      final int end = trip[2];
      timeline.merge(start, nPassengers, Integer::sum);
      timeline.merge(end, -nPassengers, Integer::sum);
    }

    for (final int passengerChange : timeline.values()) {
      currentPassengers += passengerChange;
      if (currentPassengers > capacity)
        return false;
    }

    return true;
  }
}
