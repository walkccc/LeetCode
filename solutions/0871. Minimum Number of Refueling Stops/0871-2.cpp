class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int ans = 0;
    int i = 0;  // stations's index
    int curr = startFuel;
    priority_queue<int> pq;

    while (curr < target) {
      // add all reachable stops to pq
      while (i < stations.size() && curr >= stations[i][0])
        pq.push(stations[i++][1]);
      if (pq.empty())  // we can't refuel
        return -1;
      curr += pq.top(), pq.pop();  // pop out the largest gas
      ++ans;                       // then refuel once
    }

    return ans;
  }
};
