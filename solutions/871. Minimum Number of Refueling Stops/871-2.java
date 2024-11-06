class Solution {
  public int minRefuelStops(int target, int startFuel, int[][] stations) {
    int ans = 0;
    int i = 0; // stations' index
    int curr = startFuel;
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    while (curr < target) {
      // Add all the reachable stops to maxHeap
      while (i < stations.length && curr >= stations[i][0])
        maxHeap.offer(stations[i++][1]);
      if (maxHeap.isEmpty()) // Can't be refueled.
        return -1;
      curr += maxHeap.poll(); // Pop out the largest gas.
      ++ans;                  // Then, refuel once.
    }

    return ans;
  }
}
