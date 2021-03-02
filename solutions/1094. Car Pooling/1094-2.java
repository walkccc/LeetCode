class Solution {
  public boolean carPooling(int[][] trips, int capacity) {
    int currentPassengers = 0;
    int[] timeline = new int[1001];

    for (int[] trip : trips) {
      final int nPassengers = trip[0];
      final int start = trip[1];
      final int end = trip[2];
      timeline[start] += nPassengers;
      timeline[end] -= nPassengers;
    }

    for (final int passengerChange : timeline) {
      currentPassengers += passengerChange;
      if (currentPassengers > capacity)
        return false;
    }

    return true;
  }
}
