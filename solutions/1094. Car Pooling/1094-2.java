class Solution {
  public boolean carPooling(int[][] trips, int capacity) {
    int currentPassengers = 0;
    int[] line = new int[1001];

    for (int[] trip : trips) {
      final int nPassengers = trip[0];
      final int start = trip[1];
      final int end = trip[2];
      line[start] += nPassengers;
      line[end] -= nPassengers;
    }

    for (final int passengerChange : line) {
      currentPassengers += passengerChange;
      if (currentPassengers > capacity)
        return false;
    }

    return true;
  }
}
