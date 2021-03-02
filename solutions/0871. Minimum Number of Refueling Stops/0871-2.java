class Solution {
  public int minRefuelStops(int target, int startFuel, int[][] stations) {
    int ans = 0;
    int i = 0; // stations's index
    int curr = startFuel;
    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    while (curr < target) {
      // add all reachable stops to pq
      while (i < stations.length && curr >= stations[i][0])
        pq.offer(stations[i++][1]);
      if (pq.isEmpty()) // we can't refuel
        return -1;
      curr += pq.poll(); // pop out the largest gas
      ++ans; // then refuel once
    }

    return ans;
  }
}
