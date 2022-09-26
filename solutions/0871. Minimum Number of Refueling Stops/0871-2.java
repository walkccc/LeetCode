class Solution {
  public int minRefuelStops(int target, int startFuel, int[][] stations) {
    int ans = 0;
    int i = 0; // stations's index
    int curr = startFuel;
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    while (curr < target) {
      // add all reachable stops to maxHeap
      while (i < stations.length && curr >= stations[i][0])
        maxHeap.offer(stations[i++][1]);
      if (maxHeap.isEmpty()) // we can't refuel
        return -1;
      curr += maxHeap.poll(); // pop out the largest gas
      ++ans;                  // then refuel once
    }

    return ans;
  }
}
