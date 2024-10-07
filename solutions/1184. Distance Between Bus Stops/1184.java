class Solution {
  public int distanceBetweenBusStops(int[] distance, int start, int destination) {
    int clockwise = 0;
    int counterclockwise = 0;

    if (start > destination) {
      int temp = start;
      start = destination;
      destination = temp;
    }

    for (int i = 0; i < distance.length; ++i) {
      if (i >= start && i < destination)
        clockwise += distance[i];
      else
        counterclockwise += distance[i];
    }

    return Math.min(clockwise, counterclockwise);
  }
}
